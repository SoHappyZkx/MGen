#pragma once
#include "GVar.h"
class CGAdapt :
	public CGVar
{
public:
	CGAdapt();
	~CGAdapt();

protected:
	void Adapt(int step1, int step2);
	void AdaptMpercStep(int v, int x, int i, int ii, int ei, int pi, int pei);
	void AdaptFriedlanderStep(int v, int x, int i, int ii, int ei, int pi, int pei);

	// Adapt local variables
	int slur_count; // Number of successive slurs

	// MIDI play warnings for each voice show if warning was already fired to prevent repeated warnings
	vector<int> warning_note_range;
	vector<int> warning_note_short;
	vector<int> warning_note_wrong;

	vector<int> play_transpose; // If generated notes are not in instrument range, playback is automatically transposed (semitones)
};

