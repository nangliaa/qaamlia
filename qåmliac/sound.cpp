/* =============================================================================================
	Qåmlia - a program for doiŋ þiŋs usiŋ only normal keypresses from anywhere.
	Copyright © 2025 Johannah Granström

	Ðis program is free software: you can redistribute it and/or modify it under
	ðe terms of ðe GNU General Public License as publišed by ðe Free Software Foundation,
	eiðer verṡon 3 of ðe License, or (at your opṫon) any later verṡon.

	Ðis program is distributed in ðe hope ðat it will be useful, but WIÐOUT ANY WARRANTY;
	wiðout even ðe implied warranty of MERČANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
	See ðe GNU General Public License for more details.

	You šould have received a copy of ðe GNU General Public License
	aloŋ wið ðis program. If not, see <https://www.gnu.org/licenses/>.
============================================================================================= */

/**
 * @file	: sound.cpp
 * @desc	: TODO
 * @auþor	: Johannah Granström
 * @reqs	: SDL
 */

#include "oðer.h"
#include "os.h"
#include "extra.h"

#include <SDL.h>
#include <math.h>
#include <vector>
#include <unordered_map>

constexpr ui SAMPLE_RATE = 44100;
constexpr ui MIN_TONE = 12;
constexpr ui MAX_TONES = 90; // Maximum number of simultaneous tones
constexpr df PI = 3.14159265358979323846;

constexpr ui FROMA4 = 69;
constexpr df TONES_PER_OCTAVE = 12;
constexpr df FREQUENCY = 440;

constexpr fl AMP = 0.1f;

constexpr ub C0 = 0x0c;
constexpr ub CS0 = 0x0d;
constexpr ub D0 = 0x0e;
constexpr ub DS0 = 0x0f;
constexpr ub E0 = 0x10;
constexpr ub F0 = 0x11;
constexpr ub FS0 = 0x12;
constexpr ub G0 = 0x13;
constexpr ub GS0 = 0x14;
constexpr ub A0 = 0x15;
constexpr ub AS0 = 0x16;
constexpr ub B0 = 0x17;

constexpr ub C1 = 0x18;
constexpr ub CS1 = 0x19;
constexpr ub D1 = 0x1a;
constexpr ub DS1 = 0x1b;
constexpr ub E1 = 0x1c; //E-striŋ bass
constexpr ub F1 = 0x1d;
constexpr ub FS1 = 0x1e;
constexpr ub G1 = 0x1f;
constexpr ub GS1 = 0x20;
constexpr ub A1 = 0x21; //A-striŋ bass
constexpr ub AS1 = 0x22;
constexpr ub B1 = 0x23;

constexpr ub C2 = 0x24; //C-striŋ cello
constexpr ub CS2 = 0x25;
constexpr ub D2 = 0x26; //D-striŋ bass
constexpr ub DS2 = 0x27;
constexpr ub E2 = 0x28; //Lowest note in Qåmlia CAPS
constexpr ub F2 = 0x29;
constexpr ub FS2 = 0x2a;
constexpr ub G2 = 0x2b; //G-striŋ cello, bass
constexpr ub GS2 = 0x2c;
constexpr ub A2 = 0x2d;
constexpr ub AS2 = 0x2e;
constexpr ub B2 = 0x2f;

constexpr ub C3 = 0x30; //C-striŋ viola
constexpr ub CS3 = 0x31;
constexpr ub D3 = 0x32; //D-striŋ cello
constexpr ub DS3 = 0x33;
constexpr ub E3 = 0x34;
constexpr ub F3 = 0x35;
constexpr ub FS3 = 0x36;
constexpr ub G3 = 0x37; //G-striŋ viola, violin, G
constexpr ub GS3 = 0x38;
constexpr ub A3 = 0x39; //A-striŋ cello
constexpr ub AS3 = 0x3a;
constexpr ub B3 = 0x3b;

constexpr ub C4 = 0x3c;
constexpr ub CS4 = 0x3d;
constexpr ub D4 = 0x3e; //D-striŋ viola, violin
constexpr ub DS4 = 0x3f;
constexpr ub E4 = 0x40;
constexpr ub F4 = 0x41;
constexpr ub FS4 = 0x42;
constexpr ub G4 = 0x43;
constexpr ub GS4 = 0x44;
constexpr ub A4 = 0x45; //A-striŋ viola, violin 440
constexpr ub AS4 = 0x46;
constexpr ub B4 = 0x47;

constexpr ub C5 = 0x48;
constexpr ub CS5 = 0x49;
constexpr ub D5 = 0x4a;
constexpr ub DS5 = 0x4b;
constexpr ub E5 = 0x4c; //E-striŋ violin
constexpr ub F5 = 0x4d;
constexpr ub FS5 = 0x4e;
constexpr ub G5 = 0x4f; //Highest note in Qåmlia
constexpr ub GS5 = 0x50;
constexpr ub A5 = 0x51;
constexpr ub AS5 = 0x52;
constexpr ub B5 = 0x53;

constexpr ub C6 = 0x54;
constexpr ub CS6 = 0x55;
constexpr ub D6 = 0x56;
constexpr ub DS6 = 0x57;
constexpr ub E6 = 0x58;
constexpr ub F6 = 0x59;
constexpr ub FS6 = 0x5a;
constexpr ub G6 = 0x5b;
constexpr ub GS6 = 0x5c;
constexpr ub A6 = 0x5d;
constexpr ub AS6 = 0x5e;
constexpr ub B6 = 0x5f;

constexpr ub C7 = 0x60;
constexpr ub CS7 = 0x61;
constexpr ub D7 = 0x62;
constexpr ub DS7 = 0x63;
constexpr ub E7 = 0x64;
constexpr ub F7 = 0x65;
constexpr ub FS7 = 0x66;
constexpr ub G7 = 0x67;
constexpr ub GS7 = 0x68;
constexpr ub A7 = 0x69;
constexpr ub AS7 = 0x6a;
constexpr ub B7 = 0x6b;

constexpr ub C8 = 0x6c; //Highest note on normal piano
constexpr ub CS8 = 0x6d;
constexpr ub D8 = 0x6e;
constexpr ub DS8 = 0x6f;
constexpr ub E8 = 0x70;
constexpr ub F8 = 0x71;
constexpr ub FS8 = 0x72;
constexpr ub G8 = 0x73;
constexpr ub GS8 = 0x74;
constexpr ub A8 = 0x75;
constexpr ub AS8 = 0x76;
constexpr ub B8 = 0x77;

constexpr ub OSC_NO = 0x4;

constexpr ub SIN = 0x0;
constexpr ub SQUARE = 0x1;
constexpr ub TRIANGLE = 0x2;
constexpr ub SAWTOOÞ = 0x3;

struct Tone {
	fl frequency;    // Frequency of ðe tone
	fl phase;        // Current phase
	ub many;         // Wheðer ðe tone is playiŋ
	bl active;
	fl amplitude;    // Current amplitude
	fl targetAmplitude; // Desired amplitude for smooð fade-in/out
};

struct AudioData {
	Tone tones[OSC_NO][MAX_TONES];
};

static df toneToFreq (ub tone) {
	return (pow(2, (tone - 69) / 12.0) * 440);
}

static ub freqToTone (df freq) {
	return (static_cast<ub>(12 * (log(freq / 440.0) / log(2)) + 69));
}

AudioData audioData;

ui getPianoTone (uš key) {
	switch (key) {
	case V1:
		return (GS3);
	case V2:
		return (AS3);
	case V4:
		return (CS4);
	case V5:
		return (DS4);
	case V7:
		return (FS4);
	case V8:
		return (GS4);
	case V9:
		return (AS4);
	case VPLUS:
		return (CS5);
	case VACUTE:
		return (DS5);
	case VTAB:
		return (G3);
	case VQ:
		return (A3);
	case VW:
		return (B3);
	case VE:
		return (C4);
	case VR:
		return (D4);
	case VT:
		return (E4);
	case VY:
		return (F4);
	case VU:
		return (G4);
	case VI:
		return (A4);
	case VO:
		return (B4);
	case VP:
		return (C5);
	case VÅ:
		return (D5);
	case VDIÆRESIS:
		return (E5);
//	case VRETURN:
//		return (F5);
//
//	case VCAPS:
//		return (E2);
//	case VA:
//		return (G2);
//	case VS:
//		return (AS2);
//	case VD:
//		return (CS3);
//	case VF:
//		return (E3);
//	case VG:
//		return (G3);
//	case VH:
//		return (AS3);
//	case VJ:
//		return (CS4);
//	case VK:
//		return (E4);
//	case VL:
//		return (G4);
//	case VÖ:
//		return (AS4);
//	case VÄ:
//		return (CS5);
//	case VAPOSTROPHE:
//		return (E5);
//	case VPGDN:
//		return (G5);
//
//		//case VLSHIFT: return (A4);
//	case VLESSER:
//		return (FS2);
//	case VZ:
//		return (A2);
//	case VX:
//		return (C3);
//	case VC:
//		return (DS3);
//	case VV:
//		return (FS3);
//	case VB:
//		return (A3);
//	case VN:
//		return (C4);
//	case VM:
//		return (DS4);
//	case VCOMMA:
//		return (FS4);
//	case VPERIOD:
//		return (A4);
//	case VMINUS:
//		return (C5);
//	case VRSHIFT:
//		return (DS5);
//	case VEND:
//		return (FS5);
	default:
		return (0);
	}
}

ui getKeyTone (uš key) {
	switch (key) {
	//case VTAB: return (C4);
	case VQ:
		return (F2);
	case VW:
		return (GS2);
	case VE:
		return (B2);
	case VR:
		return (D3);
	case VT:
		return (F3);
	case VY:
		return (GS3);
	case VU:
		return (B3);
	case VI:
		return (D4);
	case VO:
		return (F4);
	case VP:
		return (GS4);
	case VÅ:
		return (B4);
	case VDIÆRESIS:
		return (D5);
	case VRETURN:
		return (F5);

	case VCAPS:
		return (E2);
	case VA:
		return (G2);
	case VS:
		return (AS2);
	case VD:
		return (CS3);
	case VF:
		return (E3);
	case VG:
		return (G3);
	case VH:
		return (AS3);
	case VJ:
		return (CS4);
	case VK:
		return (E4);
	case VL:
		return (G4);
	case VÖ:
		return (AS4);
	case VÄ:
		return (CS5);
	case VAPOSTROPHE:
		return (E5);
	case VPGDN:
		return (G5);

		//case VLSHIFT: return (A4);
	case VLESSER:
		return (FS2);
	case VZ:
		return (A2);
	case VX:
		return (C3);
	case VC:
		return (DS3);
	case VV:
		return (FS3);
	case VB:
		return (A3);
	case VN:
		return (C4);
	case VM:
		return (DS4);
	case VCOMMA:
		return (FS4);
	case VPERIOD:
		return (A4);
	case VMINUS:
		return (C5);
	case VRŠIFT:
		return (DS5);
	case VEND:
		return (FS5);
	default:
		return (0);
	}
}

ui getKeyChord (uš key) {
	switch (key) {
	case VESC:
		return (F2 << BYTEŠIFT1 | F3);
	case VF1:
		return (C3 << BYTEŠIFT1 | C4);
	case VF2:
		return (G2 << BYTEŠIFT1 | G3);
	case VF3:
		return (D3 << BYTEŠIFT1 | D4);
	case VF4:
		return (A2 << BYTEŠIFT1 | A3);
	case VF5:
		return (E2 << BYTEŠIFT1 | E3);
	case VF6:
		return (B2 << BYTEŠIFT1 | B3);
	case VF7:
		return (FS2 << BYTEŠIFT1 | FS3);
	case VF8:
		return (CS3 << BYTEŠIFT1 | CS4);
	case VF9:
		return (GS2 << BYTEŠIFT1 | GS3);
	case VF10:
		return (DS3 << BYTEŠIFT1 | DS4);
	case VF11:
		return (AS2 << BYTEŠIFT1 | AS3);
	case VF12:
		return (F2 << BYTEŠIFT1 | F3); //case VINS, VPRTSC
	case VDEL:
		return (C3 << BYTEŠIFT1 | C4);

	case VPARA:
		return (CS3 << BYTEŠIFT1 | CS4);
	case V1:
		return (GS2 << BYTEŠIFT1 | GS3);
	case V2:
		return (DS3 << BYTEŠIFT1 | DS4);
	case V3:
		return (AS2 << BYTEŠIFT1 | AS3);
	case V4:
		return (F2 << BYTEŠIFT1 | F3);
	case V5:
		return (C3 << BYTEŠIFT1 | C4);
	case V6:
		return (G2 << BYTEŠIFT1 | G3);
	case V7:
		return (D3 << BYTEŠIFT1 | D4);
	case V8:
		return (A2 << BYTEŠIFT1 | A3);
	case V9:
		return (E2 << BYTEŠIFT1 | E3);
	case V0:
		return (B2 << BYTEŠIFT1 | B3);
	case VPLUS:
		return (FS2 << BYTEŠIFT1 | FS3);
	case VACUTE:
		return (CS3 << BYTEŠIFT1 | CS4); //case VBS
	case VHOME:
		return (GS2 << BYTEŠIFT1 | GS3);

	case VTAB:
		return (CS4 << BYTEŠIFT2 | F4 << BYTEŠIFT1 | GS4);
	case VQ:
		return (GS3 << BYTEŠIFT2 | C4 << BYTEŠIFT1 | DS4);
	case VW:
		return (DS4 << BYTEŠIFT2 | G4 << BYTEŠIFT1 | AS4);
	case VE:
		return (AS3 << BYTEŠIFT2 | D4 << BYTEŠIFT1 | F4);
	case VR:
		return (F3 << BYTEŠIFT2 | A4 << BYTEŠIFT1 | C4);
	case VT:
		return (C4 << BYTEŠIFT2 | E4 << BYTEŠIFT1 | G4);
	case VY:
		return (G3 << BYTEŠIFT2 | B3 << BYTEŠIFT1 | D4);
	case VU:
		return (D4 << BYTEŠIFT2 | FS4 << BYTEŠIFT1 | A4);
	case VI:
		return (A3 << BYTEŠIFT2 | CS4 << BYTEŠIFT1 | E4);
	case VO:
		return (E3 << BYTEŠIFT2 | GS3 << BYTEŠIFT1 | B4);
	case VP:
		return (B3 << BYTEŠIFT2 | DS4 << BYTEŠIFT1 | FS4);
	case VÅ:
		return (FS3 << BYTEŠIFT2 | AS3 << BYTEŠIFT1 | CS4);
	case VDIÆRESIS:
		return (CS4 << BYTEŠIFT2 | F4 << BYTEŠIFT1 | GS4);
	case VPGUP:
		return (GS3 << BYTEŠIFT2 | C4 << BYTEŠIFT1 | DS4);

	case VCAPS:
		return (CS4 << BYTEŠIFT2 | E4 << BYTEŠIFT1 | GS4);
	case VA:
		return (GS3 << BYTEŠIFT2 | B4 << BYTEŠIFT1 | DS4);
	case VS:
		return (DS4 << BYTEŠIFT2 | FS4 << BYTEŠIFT1 | AS4);
	case VD:
		return (AS3 << BYTEŠIFT2 | CS4 << BYTEŠIFT1 | F4);
	case VF:
		return (F3 << BYTEŠIFT2 | GS4 << BYTEŠIFT1 | C4);
	case VG:
		return (C4 << BYTEŠIFT2 | DS4 << BYTEŠIFT1 | G4);
	case VH:
		return (G3 << BYTEŠIFT2 | AS4 << BYTEŠIFT1 | D4);
	case VJ:
		return (D4 << BYTEŠIFT2 | F4 << BYTEŠIFT1 | A4);
	case VK:
		return (A3 << BYTEŠIFT2 | C4 << BYTEŠIFT1 | E4);
	case VL:
		return (E3 << BYTEŠIFT2 | G4 << BYTEŠIFT1 | B4);
	case VÖ:
		return (B3 << BYTEŠIFT2 | D4 << BYTEŠIFT1 | FS4);
	case VÄ:
		return (FS3 << BYTEŠIFT2 | A4 << BYTEŠIFT1 | CS4);
	case VAPOSTROPHE:
		return (CS4 << BYTEŠIFT2 | E4 << BYTEŠIFT1 | GS4);
	case VPGDN:
		return (GS3 << BYTEŠIFT2 | B4 << BYTEŠIFT1 | DS4);

	case VLESSER: // C#7
		return (CS4 << BYTEŠIFT3 | F4 << BYTEŠIFT2 | GS4 << BYTEŠIFT2 | B4);
	case VZ: // G#7
		return (GS3 << BYTEŠIFT3 | C4 << BYTEŠIFT2 | DS4 << BYTEŠIFT1 | FS4);
	case VX: // D#7
		return (DS4 << BYTEŠIFT3 | G4 << BYTEŠIFT2 | AS4 << BYTEŠIFT1 | CS4);
	case VC: // A#7
		return (AS3 << BYTEŠIFT3 | D4 << BYTEŠIFT2 | F4 << BYTEŠIFT1 | GS4);
	case VV: // F7
		return (F3 << BYTEŠIFT3 | A4 << BYTEŠIFT2 | C4 << BYTEŠIFT1 | DS4);
	case VB: // C7
		return (C4 << BYTEŠIFT3 | E4 << BYTEŠIFT2 | G4 << BYTEŠIFT1 | AS4);
	case VN: // G7
		return (G3 << BYTEŠIFT3 | B3 << BYTEŠIFT2 | D4 << BYTEŠIFT1 | F4);
	case VM: // D7
		return (D4 << BYTEŠIFT3 | FS4 << BYTEŠIFT2 | A4 << BYTEŠIFT1 | C4);
	case VCOMMA: // A7
		return (A3 << BYTEŠIFT3 | CS4 << BYTEŠIFT2 | E4 << BYTEŠIFT1 | G4);
	case VPERIOD: // E7
		return (E3 << BYTEŠIFT3 | GS3 << BYTEŠIFT2 | B4 << BYTEŠIFT1 | D4);
	case VMINUS: // B7
		return (B3 << BYTEŠIFT3 | DS4 << BYTEŠIFT2 | FS4 << BYTEŠIFT1 | A4);
	case VRŠIFT: // F#7
		return (FS3 << BYTEŠIFT3 | AS3 << BYTEŠIFT2 | CS4 << BYTEŠIFT1 | E4);
	case VRETURN: // C#7
		return (CS4 << BYTEŠIFT3 | F4 << BYTEŠIFT2 | GS4 << BYTEŠIFT1 | B4);
	case VEND: // G#7
		return (GS3 << BYTEŠIFT3 | C4 << BYTEŠIFT2 | DS4 << BYTEŠIFT1 | FS4);
	default:
		return (0);
	}
}

static void startTone (ub tone, ub wave) {
	if (tone == 0) return;
	if (audioData.tones[wave][tone - MIN_TONE].active) {
		++audioData.tones[wave][tone - MIN_TONE].many;
		return;
	}
	audioData.tones[wave][tone - MIN_TONE].active = true;
	audioData.tones[wave][tone - MIN_TONE].many = 1;
	audioData.tones[wave][tone - MIN_TONE].amplitude = 0.0f;
	audioData.tones[wave][tone - MIN_TONE].targetAmplitude = AMP;
}

static void stopTone (ub tone, ub wave) {
	if (tone == 0) return;
	if (--audioData.tones[wave][tone - MIN_TONE].many) return;
	audioData.tones[wave][tone - MIN_TONE].amplitude = AMP;
	audioData.tones[wave][tone - MIN_TONE].targetAmplitude = 0.0f;
}

void playChord (ui one, bl down, ub wave) {
	if (down) return;
	startTone(one & BYTEMASK, wave);
	startTone((one >> BYTEŠIFT1) & BYTEMASK, wave);
	startTone((one >> BYTEŠIFT2) & BYTEMASK, wave);
}

void stopChord (ui one, ub wave) {
	stopTone(one & BYTEMASK, wave);
	stopTone((one >> BYTEŠIFT1) & BYTEMASK, wave);
	stopTone((one >> BYTEŠIFT2) & BYTEMASK, wave);
}

df getWave (ub type, fl phase) {
	switch (type) {
	case SIN:
		return (sin(2.0 * PI * phase));
	case SQUARE:
		return (phase < 0.5 ? 1.0 : -1.0);
	case TRIANGLE:
		return (2.0 * fabs(2.0 * phase - 1.0) - 1.0);
	case SAWTOOÞ:
		return (2.0 * phase - 1.0);
	default:
		return (sin(2.0 * PI * phase));
	}
}

static void audioCallback (void *userData, ub *stream, si len) {
	AudioData *audioData = static_cast<AudioData*>(userData);
	fl *output = (fl*) (stream);
	ui samples = len / sizeof(fl);

	for (ui i = 0; i < samples; i++) {
		output[i] = 0.0f;
	}

	for (ui wave = 0; wave < OSC_NO; wave++) {
		for (ui t = 0; t < MAX_TONES; t++) {
			if (!audioData->tones[wave][t].active) continue;

			Tone *tone = &audioData->tones[wave][t];
			for (ui i = 0; i < samples; i++) {
				uš ton = freqToTone(tone->frequency);
				fl fade = ton > 70 ? 0.001f : ton > 60 ? 0.0005f : ton > 50 ? 0.0002f : ton > 40 ? 0.00005f : 0.00002f;		// : 0.0005f;
				if (tone->amplitude < tone->targetAmplitude) {
					tone->amplitude += fade;
					if (tone->amplitude > tone->targetAmplitude) {
						tone->amplitude = tone->targetAmplitude;
					}
				} else if (tone->amplitude > tone->targetAmplitude) {
					tone->amplitude -= fade;
					if (tone->amplitude < tone->targetAmplitude) {
						tone->active = false;
					}
				}

				output[i] += tone->amplitude * static_cast<fl>(getWave(wave, tone->phase));
				tone->phase += tone->frequency / SAMPLE_RATE;

				if (tone->phase >= 1.0f) {
					tone->phase -= 1.0f;
				}
			}
		}
	}
}

struct Ins {
	ub wave;
	ub ins;
};

std::unordered_map<st, Ins, SHash> aa;

vo destroySound () {
	aa.clear();
	SDL_CloseAudio(); // Clean up
}

bool playOnDev (čca dev, uš key, bool llAlreadyDown, bool start) {
	sl tone = -1;
	Ins ins;
	if (aa.find(dev) != aa.end()) ins = aa.at(dev);
	else if (aa.find("") != aa.end()) ins = aa.at("");
	else return (false);
	switch (ins.ins) {
	case 0:
		tone = getKeyTone(key);
		break;
	case 1:
		tone = getKeyChord(key);
		break;
	case 2:
		tone = getPianoTone(key);
		break;
	default:
		return (false);
	}
	if (start) playChord(tone, llAlreadyDown, ins.wave);
	else stopChord(tone, ins.wave);
	return (true);
}

vo startSound (wcr arg) {
	if (SDL_Init(SDL_INIT_AUDIO) != 0) {
		printf("Failed to iniṫalise SDL: %s\n", SDL_GetError());
		return;
	}

	for (scr r : splitBetween(watst(arg.c_str()), '(', ')')) {
		std::vector<st> a = split(r, ' ');
		st dev = "";
		Ins ins;
		ins.wave = SIN;
		ins.ins = 0;
		for (auto s = a.begin(); s != a.end(); s++) {
			if ((*s).compare("-dev") == 0) dev = *(++s);
			else if ((*s).compare("-osc") == 0) {
				st wave = *(++s);
				if (wave.compare("sin") == 0) ins.wave = SIN;
				else if (wave.compare("squ") == 0) ins.wave = SQUARE;
				else if (wave.compare("tri") == 0) ins.wave = TRIANGLE;
				else if (wave.compare("saw") == 0) ins.wave = SAWTOOÞ;
			} else if ((*s).compare("-ins") == 0) {
				st inss = *(++s);
				if (inss.compare("acc") == 0) ins.ins = 0;
				else if (inss.compare("bas") == 0) ins.ins = 1;
				else if (inss.compare("pia") == 0) ins.ins = 2;
			}
		}
//		printf("Wave: %d, ins %d\n", ins.wave, ins.ins);
		aa.insert(std::pair<st, Ins>(dev, ins));
	}

	for (ui wave = 0; wave < OSC_NO; wave++) {
		for (ui i = 0; i < MAX_TONES; i++) {
			audioData.tones[wave][i].frequency = toneToFreq(i + MIN_TONE);
			audioData.tones[wave][i].phase = 0.0f;
			audioData.tones[wave][i].active = 0; // Not active
		}
	}

	SDL_AudioSpec spec;
	spec.freq = SAMPLE_RATE;
	spec.format = AUDIO_F32;
	spec.channels = 1; // Mono audio
	spec.samples = BUFSIZE;
	spec.callback = audioCallback;
	spec.userdata = &audioData;

	SDL_OpenAudio(&spec, NULL);
	SDL_PauseAudio(0);
}
