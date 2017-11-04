#pragma once

#include "pvector.h"

#define MGR_VERSION "1.9" // Version of MGR file format (should change only when format changes)
#define MAX_VOICE 200
#define MAX_INSTR 100
// Number of status lines
#define STATUS_LINES 9
// Number of log tabs
#define LOG_TABS 9
// Check for new logs every X ms
#define LOG_TIMER 50
// Send no more than Y logs every time when checking (maximum stable frequency is LOG_MAX_SEND / LOG_TIMER)
#define LOG_MAX_SEND 5
// Maximum number of logs in buffer (maximum burst)
#define MAX_LOG_BUFFER 400
// Maximum number of logs saved to file on autosave in each tab
#define MAX_SAVED_LOGS 10000
// Warn if status frequency is above this value
#define WARN_STATUS_FREQ 1000
// Warn if log frequency is above this value
#define WARN_LOG_FREQ 1000

// Convert chromatic to diatonic
#define CC_C(note, tonic, minor) (minor?m_CC_C(note, tonic):maj_CC_C(note, tonic))
#define maj_CC_C(note, tonic) (chrom_to_dia[(note + 12 - tonic) % 12] + ((note + 12 - tonic) / 12) * 7)
#define m_CC_C(note, tonic) (m_chrom_to_dia[(note + 12 - tonic) % 12] + ((note + 12 - tonic) / 12) * 7)

// Convert diatonic to chromatic
#define C_CC(note, tonic, minor) (minor?m_C_CC(note, tonic):maj_C_CC(note, tonic))
#define maj_C_CC(note, tonic) (dia_to_chrom[note % 7] + (note / 7 - 1) * 12 + tonic)
#define m_C_CC(note, tonic) (m_dia_to_chrom[note % 7] + (note / 7 - 1) * 12 + tonic)

typedef  unsigned long int  ub4; // a ub4 is an unsigned 4-byte quantity

const int int_meaning[] = { 0, -1, 0, -1, 0, 1, -1 };
const int dia_to_chrom[] = { 0, 2, 4, 5, 7, 9, 11 };
const int chrom_to_dia[] = { 0, 0, 1, 1, 2, 3, 3, 4, 4, 5, 5, 6 };
const int diatonic[] = { 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1 };
const int m_dia_to_chrom[] = { 0, 2, 3, 5, 7, 8, 10 };
const int m_chrom_to_dia[] = { 0, 0, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6 };
const int m_diatonic[] = { 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0 };
const int m_diatonic_full[] = { 1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1 };

#define ARTIC_LEGATO 0
#define ARTIC_SLUR 1
#define ARTIC_NONLEGATO 2
#define ARTIC_EXACT 3
#define ARTIC_STACCATO 4
#define ARTIC_REBOW 5
#define ARTIC_RETRIGGER 6
#define ARTIC_SPLITPO_CHROM 7
#define ARTIC_SPLITPO_MIX 8
#define ARTIC_SPLITPO_ARAB 9
#define ARTIC_SPLITPO_PENT 10
#define ARTIC_GLISS 11
#define ARTIC_GLISS2 12
#define ARTIC_END_SFL 13
#define ARTIC_END_PBD 14
#define ARTIC_END_VIB2 15
#define ARTIC_END_VIB 16

const CString ArticName[] = {
	"Legato", // 0
	"Slur", // 1
	"Nonlegato", // 2
	"Exact", // 3
	"Staccato", // 4
	"Retrigger rebow", // 5
	"Retrigger", // 6
	"Split portamento chromatic", // 7
	"Split portamento mixed", // 8
	"Split portamento arabic", // 9
	"Split portamento pentatonic", // 10
	"Gliss", // 11
	"Gliss2", // 12
	"Short fall ending", // 13
	"Pitchbend down ending", // 14
	"Vibrato2 ending", // 15
	"Vibrato ending" // 16
};

#define INSTR_PIANO 0
#define INSTR_VIOLIN 1
#define INSTR_TRUMPET 11
#define INSTR_FLUTE 6

/*
const CString InstName[] = {
	"Piano", // 0
	"Violin", // 1
	"Violin2", // 2
	"Viola", // 3
	"Cello", // 4
	"Bass", // 5
	"Flute", // 6
	"Oboe", // 7
	"Clarinet", // 8
	"Bassoon", // 9
	"Horn", // 10
	"Trumpet", // 11
	"Trombone", // 12
	"Tuba", // 13
	"Harp", // 14
	"Percussion" // 15
};
*/

const CString NoteName[] = {
	"C", // 0
	"C#", // 1
	"D", // 2
	"D#", // 3
	"E", // 4
	"F", // 5
	"F#", // 6
	"G", // 7
	"G#", // 8
	"A", // 9
	"A#", // 10
	"B" // 11
};

const CString NoteName2[] = {
	"C", // 0
	"Db", // 1
	"D", // 2
	"Eb", // 3
	"E", // 4
	"F", // 5
	"Gb", // 6
	"G", // 7
	"Ab", // 8
	"A", // 9
	"Bb", // 10
	"B" // 11
};

#define SQR(x) pow(x, 2)
#define SQRT(x) pow(x, 0.5)

class CGLib
{
public:
	static void read_file_sv(CString fname, vector<CString> &sv);
	static void write_file_sv(ofstream &fs, vector<CString> &sv);
	static void copy_file(CString sName, CString dName);
	static void AppendLineToFile(CString fname, CString st);
	static void AppendLineInFile(CString fname, int line, CString st);
	static void CheckVar(CString* sName, CString* sValue, char* sSearch, int* Dest, int lmin = -1000000, int lmax = -1000000);
	static void LoadVar(CString * sName, CString * sValue, char * sSearch, long long * Dest);
	static void CheckVar(CString * sName, CString * sValue, char * sSearch, float * Dest, float lmin = -1000000, float lmax = -1000000);
	static void LoadVectorPar2(CString * sName, CString * sValue, char * sSearch, vector<int>& Dest, int value, int lmin = -1000000, int lmax = -1000000);
	static void CheckLimits(CString * sName, int * Dest, int lmin, int lmax);
	static void CheckLimits(CString * sName, float * Dest, float lmin, float lmax);
	static void CheckRange(CString * sName, CString * sValue, char * sSearch, int * vmin, int * vmax, int lmin= -1000000, int lmax= -1000000);
	static void CheckRange(CString * sName, CString * sValue, char * sSearch, float * vmin, float * vmax, float lmin = -1000000, float lmax = -1000000);
	static void LoadVar(CString * sName, CString * sValue, char * sSearch, CString * Dest);
	static void StringToVector(CString * sValue, CString stDelim, vector<int>& Dest, int lmin = -1000000, int lmax = -1000000);
	static void LoadVectorPar(CString * sName, CString * sValue, char * sSearch, vector<int>& Dest, int lmin = -1000000, int lmax = -1000000);
	static void Tokenize(const CString & s, vector<CString>& tokens, const CString & delim);
	static void GetVint(const CString &st, vector<int> &res);
	static int CheckInclude(CString st, CString fname, CString & iname);
	static CString GetLinkedPath(CString st, CString fname);
	static void LoadNote(CString * sName, CString * sValue, char * sSearch, int * Dest);
	static CString FormatTime(int sec);
	static bool dirExists(CString dirName_in);
	static bool fileExists(CString dirName_in);
	static bool nodeExists(CString dirName_in);
	static CString ext_from_path(CString path);
	static CString noext_from_path(CString path);
	static CString fname_from_path(CString path);
	static CString bname_from_path(CString path);
	static CString dir_from_path(CString path);
	static CString GetNoteName(int n);
	static int GetNoteI(CString &st);
	static int GetPC(CString &st);
	static int MatchVectors(vector <int> &v1, vector <int> &v2, int i1, int i2);
	static void vfill(vector<int> &v, int value);
	static int vsum(vector<int> &v);
	static int vmax(vector<int> &v);
	static int vmin(vector<int> &v);

	static CString HumanFloat(float f);

	static CString HumanFloatPrecision(float f);

protected:
	// Mathematics
	int randbw(int n1, int n2); // Random between two numbers
	float rand01(); // Random float between 0 and 1
	// Random
	void isaac();
	void randinit(int flag);
	unsigned int rand2();
	// Load
	static int parameter_found;

public:
	CGLib();
	virtual ~CGLib();

	static int FileHasHeader(CString fname, CString header);
	
	static DWORD GetRed(DWORD col) { return (col >> 16) & 0xff; }
	static DWORD GetGreen(DWORD col) { return (col >> 8) & 0xff; }
	static DWORD GetBlue(DWORD col) { return col & 0xff; }
	static DWORD GetAlpha(DWORD col) { return (col >> 24) & 0xff; }
	static DWORD MakeColor(DWORD alpha, DWORD red, DWORD green, DWORD blue)
		{ return (alpha << 24) + (red << 16) + (green << 8) + blue; }

	DWORD Run(CString fname, CString par, int delay = 0);

	static long long time();

	static FILETIME fileTime(CString fname);

	static void start_time();

	static long long abstime();

	void InitRandom();
	void TestRandom(); // Tests random generator
	void TestSmoothRandom(); // Tests smooth random generator
	static void EscalateLog(CString st);
	static void WriteLog(int i, CString st);
	static void SetStatusText(int line, CString st);

	//Test
	static void TestVSet();

public:
	// Thread interface
	static char* APP_VERSION;
	static int debug_level;
	static int play_enabled;
	static int show_lining;
	static HWND m_hWnd;
	static UINT WM_DEBUG_MSG, WM_STATUS_MSG;
	static int can_send_log; // If thread can send log to MainFrame (disabled OnClose)
	static int m_ci; // If continuous integration is in progress
	static int m_testing; // If currently testing
	static int m_test_sec; // How long to test in seconds
	static CString m_cline2; // Command line filename
	static int exitcode; // Exit code of application
	UINT WM_GEN_FINISH = 0;
	timed_mutex mutex_animate; // Mutex to lock data changes in CF1/CP1/CA1/CA2 algorithms for InfoDlg
	timed_mutex mutex_output;
	static timed_mutex mutex_log;
	int need_exit = 0; // If thread needs to exit due to generation abort
	vector<vector<CString>> logs; // Logs array

	// Status output
	static vector<CString> oinfo; // Strings of algorithm output status
	static vector<int> oinfo_changed; // If string changed
	static vector<long long> status_updates;
	
	// Log output
	static vector<queue<CString>> log_buffer; // Logs buffer
	static vector<int> log_buffer_size; // Logs buffer size
	static vector<int> warn_log_buffer; // =1 if Log buffer overflow
	static vector<long long> logs_sent;

protected:
  // Random generator
	ub4 randrsl[256], randcnt = 0; // external results
	ub4 rmm[256];  // internal state
	ub4 raa = 0, rbb = 0, rcc = 0;
	int cur_rand = 0, cur_rand2 = 0;

	// Time
	static long long first_time;

	int error = 0;
	template<typename T> void vpop_front(vector<T> &v, int count);
	template<typename T> void vpush_front(vector<T> &v, T element, int count);
};

// Pop front vector elements
template<typename T> void CGLib::vpop_front(vector<T> &v, int count) {
	// Copy vector back
	for (int i = 0; i < v.size() - count; ++i) v[i] = v[i + count];
	// Remove last elements
	for (int i = 0; i < count; ++i) v.pop_back();
}

// Push front vector elements
template<typename T> void CGLib::vpush_front(vector<T> &v, T element, int count) {
	// Grow vector (actually, elements are loaded, but it is not important which elements because they will be overwritten in the next step)
	for (int i = 0; i < count; ++i) v.push_back(element);
	// Copy vector forward
	for (int i = 0; i < v.size() - count; ++i) v[i + count] = v[i];
	// Assign new elements
	for (int i = 0; i < count; ++i) v[i] = element;
}
