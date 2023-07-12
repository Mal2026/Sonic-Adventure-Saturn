#include "pch.h"
#include "SADXModInfo.h"
#include "object model code.h"
#include "SADXVariables.h"
#include "IniFile.hpp"

#define ReplacePVM(a, b) helperFunctions.ReplaceFile("system\\" a ".PVM", "system\\" b ".PVM");
#define ReplaceTex(pvm, pvr, folder, pngname, gbix, x, y) helperFunctions.ReplaceTexture(pvm, pvr, (std::string(path) + "\\textures\\" folder "\\" pngname ".png").c_str(), gbix, x, y);
#define upgradecheck(chara,name) bool Disable##name = settings->getBool(#chara, "Disable"#name, true)

enum Big { SBig, SBigLE, SPBig, SBFalse };

bool CopyrightFreeMusic = false;
bool SatThemeM = true;
bool SatThemeS = true;
bool SatThemeT = true;
bool SatThemeK = true;
bool SatThemeA = true;
bool SatThemeE = true;
bool SatThemeSS = true;
bool SatThemeC = true;
bool SSMusic = true;
bool MRMusic = true;
bool EGMusic = true;
bool ECMusic = true;
bool WVMusic = true;
bool CMusic = true;
bool ICMusic = true;
bool TPMusic = true;
bool SHMusic = true;
bool RMMusic = true;
bool SDMusic = true;
bool HSMusic = true;
bool LWMusic = true;
bool FEMusic = true;
bool SCMusic = true;
bool TCMusic = true;
bool EVMusic = true;
bool MenuMusic = true;
bool JMusic = true;
bool BMusic = true;
bool SA1SSFX = true;
bool SatEmeraldCoast = true;
bool SatSpeedHighway = true;
bool SatRedMountain = true;
bool SatSSChaoGar = true;
bool SatECChaoGar = true;
bool StationSquare = true;
bool GUISAT = true;
bool TGUISAT = true;
bool RGUISAT = true;
bool LifeSAT = true;
bool FontSAT = true;
bool MenuSAT = true;
bool SaturnBrand = true;
bool JamAnim = true;
bool TitleCards = true;
static bool JamSpring = true;
static bool Monitor = true;
static bool SaturnTikal = true;
static int SaturnBig = SBig;
static bool SaturnMetalSonic = true;
static bool SaturnEgg = true;
static bool SaturnBadniks = true;
static bool Mal = true;


DataPointer(NJS_OBJECT, Eggmobile0_Object, 0x2EEB524);

FunctionPointer(void, PlaySonicIdleVoice, (int a1), 0x442360);


//Spring model replacement 
void Init_Springs()
{

	*(NJS_MODEL_SADX*)0x008B6010 = attach_8DB202BD6F86CF7889E;
	*(NJS_MODEL_SADX*)0x008B6470 = attach_8DB202BD6F86CBC017C;
	*(NJS_MODEL_SADX*)0x008B679C = attach_8DB202BD6F86C0569D5;//Spring

	*(NJS_MODEL_SADX*)0x008B5498 = attach_8DB202BE3D3CE60CA5B;
	*(NJS_MODEL_SADX*)0x008B58F8 = attach_8DB202BE3D3CE3808F0;
	*(NJS_MODEL_SADX*)0x008B5C10 = attach_8DB202BE3D3CDD1692D;//Rotatable Spring
}

//Item Capsule model replacement 
void Init_Monitor()
{
	*(NJS_MODEL_SADX*)0x008BEAA8 = attach_004BEAA8;
	*(NJS_MODEL_SADX*)0x008BF260 = attach_004BF260;
	*(NJS_MODEL_SADX*)0x008BE270 = attach_004BE270;//Classic Item Monitor
}


//Model replacement for config
wchar_t* ConvertCharToWChar(const char* value)//Just makes things more efficient 
{
	const size_t cSize2 = strlen(value) + 1;
	wchar_t* wcharVariable = new wchar_t[cSize2];
	mbstowcs(wcharVariable, value, cSize2);
	return wcharVariable;
}



//DLL File Replacement
void LoadSaturnDLL(std::wstring iniFile, std::wstring modDir, const HelperFunctions& helper)
{
	std::wstring iniFilePathString = modDir + L"\\system\\" + iniFile + L".ini";
	helper.LoadDLLData(iniFilePathString.c_str(), modDir.c_str());
}

//EXE File Replacement
void LoadSaturnEXE(std::wstring iniFile, std::wstring modDir, const HelperFunctions& api)
{
	std::wstring iniFileFullPath = modDir + L"\\system\\" + iniFile + L".ini";
	api.LoadEXEData(iniFileFullPath.c_str(), modDir.c_str());
}

void LoadLandTable(LandTableInfo** info, const char* name, const HelperFunctions& helperFunctions, NJS_TEXLIST* texlist)
{
	std::string fullPath = "system\\landtables\\";
	fullPath = fullPath + name + ".sa1lvl";

	LandTableInfo* land = new LandTableInfo(helperFunctions.GetReplaceablePath(fullPath.c_str()));

	if (land->getlandtable() == nullptr)
	{
		delete land;
		*info = nullptr;
	}

	else
	{
		if (texlist != nullptr)
		{
			land->getlandtable()->TexList = texlist;
		}

		*info = land;
	}
}

//void LevelLoader(unsigned __int16 levelact, const char* filename, NJS_TEXLIST* landTableTexlist = NULL, _OBJ_LANDTABLE* landtablePointer = NULL)


LandTableInfo* MDL_SaturnRM1;
LandTableInfo* MDL_SaturnRM2;

NJS_TEXNAME TEX_SRM1[46] = { 0 };
NJS_TEXLIST TEXLIST_SRM1 = { arrayptrandlength(TEX_SRM1) };

NJS_TEXNAME TEX_SRM2[46] = { 0 };
NJS_TEXLIST TEXLIST_SRM2 = { arrayptrandlength(TEX_SRM2) };

//void SaturnRM()
//{
	//LoadLandTable(&MDL_SaturnRM1, "RedMountain1SAT_Landtable", HelperFunctionsGlobal, &TEXLIST_SRM1);
	//LoadLandTable(&MDL_SaturnRM2, "RedMountain2SAT_Landtable", HelperFunctionsGlobal, &TEXLIST_SRM2);

	//GeoLists[LevelIDs_RedMountain * 8] = MDL_SaturnRM1->getlandtable();
	//GeoLists[LevelIDs_RedMountain * 8 + 1] = MDL_SaturnRM2->getlandtable();
//}

NJS_TEXNAME TEX_SaturnRM1_DX[47] = { 0 };
NJS_TEXLIST TEXLIST_SaturnRM1_DX = { arrayptrandlength(TEX_SaturnRM1_DX) };

NJS_TEXNAME TEX_SaturnRM2_DX[47] = { 0 };
NJS_TEXLIST TEXLIST_SaturnRM2_DX = { arrayptrandlength(TEX_SaturnRM2_DX) };

LandTableInfo* MDL_SaturnRM1_DX = nullptr;
LandTableInfo* MDL_SaturnRM2_DX = nullptr;


void INIT_SaturnRM_DX()
{
	LoadLandTable(&MDL_SaturnRM1_DX, "SaturnRM1_Landtable", HelperFunctionsGlobal, &TEXLIST_SaturnRM1_DX);
	LoadLandTable(&MDL_SaturnRM2_DX, "SaturnRM2_Landtable", HelperFunctionsGlobal, &TEXLIST_SaturnRM2_DX);

	GeoLists[LevelIDs_RedMountain * 8] = MDL_SaturnRM1_DX->getlandtable();
	GeoLists[LevelIDs_RedMountain * 8 + 1] = MDL_SaturnRM2_DX->getlandtable();
}


void INIT_SaturnRM_DC()
{
	LevelLoader(LevelAndActIDs_RedMountain2, "SYSTEM\\data\\stg05_mountain\\RedMountain2SAT_Landtable_DC.sa1lvl", &texlist_mountain02);
}

__declspec(dllexport) void UpgradeChecks(const char* path, const HelperFunctions& helperFunctions)
{
	const IniFile* settings = new IniFile(std::string(path) + "\\config.ini");
	upgradecheck(Big, PowerRod);
	upgradecheck(Big, LifeRing);
	if (DisablePowerRod && DisableLifeRing)
		WriteJump((void*)0x491270, (void*)0x4913BF);
	else if (DisablePowerRod)
		WriteJump((void*)0x49136E, (void*)0x4913BF);
	else if (DisableLifeRing)
		WriteJump((void*)0x491270, (void*)0x49136E);
	if (DisablePowerRod)
		WriteData<3>((void*)0x4913CA, 0x90u); // extra instruction
}



//Eggmans event mobile left arm indice list
uint16_t Eggman_LeftArmIndices[] = {
	3, 5,
	8, 2,
	11, 0,
};

//Eggmans event mobile right arm indice list
uint16_t Eggman_RightArmIndices[] = {
	8, 5,
	5, 3,
	11, 1,
};

void InitEggmobilenWeldInfo_r()
{
	//Eggman's event mobile left arm
	EggmanWeldInfo[0].BaseModel = &Eggmobile0_Object;
	EggmanWeldInfo[0].ModelA = (NJS_OBJECT*)0x02AE4FE0;
	EggmanWeldInfo[0].ModelB = (NJS_OBJECT*)0x02AE4AFC;
	EggmanWeldInfo[0].VertexPairCount = (uint8_t)(LengthOfArray(Eggman_LeftArmIndices) / 2);
	EggmanWeldInfo[0].WeldType = 3;
	EggmanWeldInfo[0].anonymous_5 = 0;
	EggmanWeldInfo[0].VertexBuffer = 0;
	EggmanWeldInfo[0].VertIndexes = Eggman_LeftArmIndices;

	//Eggman's event mobile right arm
	EggmanWeldInfo[1].BaseModel = &Eggmobile0_Object;
	EggmanWeldInfo[1].ModelA = (NJS_OBJECT*)0x02AE33F8;
	EggmanWeldInfo[1].ModelB = (NJS_OBJECT*)0x02AE2F14;
	EggmanWeldInfo[1].VertexPairCount = (uint8_t)(LengthOfArray(Eggman_RightArmIndices) / 2);
	EggmanWeldInfo[1].WeldType = 3;
	EggmanWeldInfo[1].anonymous_5 = 0;
	EggmanWeldInfo[1].VertexBuffer = 0;
	EggmanWeldInfo[1].VertIndexes = Eggman_RightArmIndices;

}





//Makes it so Metal Sonic doesn't use Sonic's idle voice lines
void PlaySonicIdleVoice_r(int a1)
{
	if (MetalSonicFlag)
	{
		PlayVoice(2044 + rand() % 5);
	}
	else PlaySonicIdleVoice(a1);
}


//Audio 
void initConfig(const char* path, const HelperFunctions& helperFunctions) 
{
	IniFile config(std::string(path) + "\\config.ini");
	SaturnMetalSonic = config.getBool("SaturnSkins", "SaturnMetalSonic", true);
	SaturnTikal = config.getBool("SaturnSkins", "SaturnTikal", true);
	std::string SaturnBig_String = "SBig";
	SaturnBig_String = config.getString("SaturnSkins", "SaturnBig", "SBig");
	if (SaturnBig_String == "SBig") SaturnBig = SBig;
	if (SaturnBig_String == "SBigLE") SaturnBig = SBigLE;
	if (SaturnBig_String == "SPBig") SaturnBig = SPBig;
	if (SaturnBig_String == "SBFalse") SaturnBig = SBFalse;
	SaturnBadniks = config.getBool("SaturnSkins", "SaturnBadniks", true);
	SaturnEgg = config.getBool("SaturnSkins", "SaturnEgg", true);
	Mal = config.getBool("SaturnSkins", "Mal", true);
	CopyrightFreeMusic = config.getBool("RFMusic", "CopyrightFreeMusic", false);
	SatThemeM = config.getBool("SThemes", "SatThemeM", true);
	SatThemeS = config.getBool("SThemes", "SatThemeS", true);
	SatThemeT = config.getBool("SThemes", "SatThemeT", true);
	SatThemeK = config.getBool("SThemes", "SatThemeK", true);
	SatThemeA = config.getBool("SThemes", "SatThemeA", true);
	SatThemeE = config.getBool("SThemes", "SatThemeE", true);
	SatThemeSS = config.getBool("SThemes", "SatThemeSS", true);
	SatThemeC = config.getBool("SThemes", "SatThemeC", true);
	SSMusic = config.getBool("SATMusic", "SSMusic", true);
	MRMusic = config.getBool("SATMusic", "MRMusic", true);
	EGMusic = config.getBool("SATMusic", "EGMusic", true);
	ECMusic = config.getBool("SATMusic", "ECMusic", true);
	WVMusic = config.getBool("SATMusic", "WVMusic", true);
	CMusic = config.getBool("SATMusic", "CMusic", true);
	ICMusic = config.getBool("SATMusic", "ICMusic", true);
	TPMusic = config.getBool("SATMusic", "TPMusic", true);
	SHMusic = config.getBool("SATMusic", "SHMusic", true);
	RMMusic = config.getBool("SATMusic", "RMMusic", true);
	SDMusic = config.getBool("SATMusic", "SDMusic", true);
	HSMusic = config.getBool("SATMusic", "HSMusic", true);
	LWMusic = config.getBool("SATMusic", "LWMusic", true);
	FEMusic = config.getBool("SATMusic", "FEMusic", true);
	SCMusic = config.getBool("SATMusic", "SCMusic", true);
	TCMusic = config.getBool("SATMusic", "TCMusic", true);
	EVMusic = config.getBool("SATMusic", "EVMusic", true);
	MenuMusic = config.getBool("SATMusic", "MenuMusic", true);
	JMusic = config.getBool("SATMusic", "JMusic", true);
	BMusic = config.getBool("SATMusic", "BMusic", true);
	SA1SSFX = config.getBool("SFX", "SA1SSFX", true);
	GUISAT = config.getBool("GUI", "GUISAT", true);
	TGUISAT = config.getBool("GUI", "TGUISAT", true);
	LifeSAT = config.getBool("GUI", "LifeSAT", true);
	FontSAT = config.getBool("GUI", "FontSAT", true);
	MenuSAT = config.getBool("GUI", "MenuSAT", true);
	RGUISAT = config.getBool("GUI", "RGUISAT", true);
	SaturnBrand = config.getBool("GUI", "SaturnBrand", true);
	JamAnim = config.getBool("Beta", "JamAnim", true);
	TitleCards = config.getBool("Beta", "TitleCards", true);
	JamSpring = config.getBool("Obj", "JamSpring", true);
	Monitor = config.getBool("Obj", "Monitor", true);
	SatEmeraldCoast = config.getBool("Stages", "SatEmeraldCoast", true);
	SatSpeedHighway = config.getBool("Stages", "SatSpeedHighway", true);
	SatRedMountain = config.getBool("Stages", "SatRedMountain", true);
	SatSSChaoGar = config.getBool("Stages", "SatSSChaoGar", true);
	SatECChaoGar = config.getBool("Stages", "SatECChaoGar", true);
	StationSquare = config.getBool("Stages", "StationSquare", true);
	


	if (CopyrightFreeMusic)
	{
		helperFunctions.ReplaceFile("system\\sounddata\\bgm\\wma\\ecoast1.wma", "system\\sounddata\\bgm\\RoyaltyFreebgm\\ecoast1_free.adx");
		helperFunctions.ReplaceFile("system\\sounddata\\bgm\\wma\\ecoast2.wma", "system\\sounddata\\bgm\\RoyaltyFreebgm\\ecoast2_free.adx");
		helperFunctions.ReplaceFile("system\\sounddata\\bgm\\wma\\highway1.wma", "system\\sounddata\\bgm\\RoyaltyFreebgm\\highway1_free.adx");
		helperFunctions.ReplaceFile("system\\sounddata\\bgm\\wma\\scramble.wma", "system\\sounddata\\bgm\\RoyaltyFreebgm\\scramble_free.adx");
		helperFunctions.ReplaceFile("system\\sounddata\\bgm\\wma\\mstcln.wma", "system\\sounddata\\bgm\\RoyaltyFreebgm\\mstcln_free.adx");
		helperFunctions.ReplaceFile("system\\sounddata\\bgm\\wma\\s_square.wma", "system\\sounddata\\bgm\\RoyaltyFreebgm\\s_square_free.adx");
		helperFunctions.ReplaceFile("system\\sounddata\\bgm\\wma\\twnklpk2.wma", "system\\sounddata\\bgm\\RoyaltyFreebgm\\twnklpk2_free.adx");
	}

	else if (ECMusic && TPMusic && SHMusic && SCMusic && MRMusic && SSMusic)
	{
		helperFunctions.ReplaceFile("system\\SoundData\\bgm\\wma\\ecoast1.wma", "system\\sounddata\\bgm\\satmusic\\ecoast1_sat.adx");
		helperFunctions.ReplaceFile("system\\SoundData\\bgm\\wma\\ecoast2.wma", "system\\sounddata\\bgm\\satmusic\\ecoast2_sat.adx");
		helperFunctions.ReplaceFile("system\\SoundData\\bgm\\wma\\twnklpk2.wma", "system\\sounddata\\bgm\\satmusic\\twinkle2_sat.adx");
		helperFunctions.ReplaceFile("system\\SoundData\\bgm\\wma\\highway1.wma", "system\\sounddata\\bgm\\satmusic\\highway1_sat.adx");
		helperFunctions.ReplaceFile("system\\SoundData\\bgm\\wma\\scramble.wma", "system\\sounddata\\bgm\\satmusic\\shooter_sat.adx");
		helperFunctions.ReplaceFile("system\\SoundData\\bgm\\wma\\mstcln.wma", "system\\sounddata\\bgm\\satmusic\\mysticruin_sat.adx");
		helperFunctions.ReplaceFile("system\\SoundData\\bgm\\wma\\s_square.wma", "system\\sounddata\\bgm\\satmusic\\s_square_sat.adx");
	}

	
	
	
	if (SatThemeM)
	{
		helperFunctions.ReplaceFile("system\\SoundData\\bgm\\wma\\mainthem.wma", "system\\sounddata\\saturn themes\\bgm\\wma\\mainthemS.mp3");
		helperFunctions.ReplaceFile("system\\SoundData\\bgm\\wma\\chaos_p1.wma", "system\\sounddata\\saturn themes\\bgm\\wma\\chaos_p1S.adx");
		helperFunctions.ReplaceFile("system\\SoundData\\bgm\\wma\\title.wma", "system\\sounddata\\saturn themes\\bgm\\wma\\titleS.mp3");
		helperFunctions.ReplaceFile("system\\SoundData\\bgm\\wma\\title2.wma", "system\\sounddata\\saturn themes\\bgm\\wma\\title2S.mp3");

	}
	
	if (SatThemeS)
	{
		Soundtest_Theme[1].Name = "SONIC: Sonic Boom";
		helperFunctions.ReplaceFile("system\\SoundData\\bgm\\wma\\advsonic.wma", "system\\sounddata\\saturn themes\\bgm\\wma\\advsonicS.adx");
		helperFunctions.ReplaceFile("system\\SoundData\\bgm\\wma\\sonic.wma", "system\\sounddata\\saturn themes\\bgm\\wma\\sonicS.mp3");
		helperFunctions.ReplaceFile("system\\SoundData\\bgm\\wma\\thesonic.wma", "system\\sounddata\\saturn themes\\bgm\\wma\\thesonicS.mp3");
	}

	if (SatThemeT)
	{
		Soundtest_Theme[2].Name = "MILES: Cosmic Eternity";
		helperFunctions.ReplaceFile("system\\SoundData\\bgm\\wma\\advmiles.wma", "system\\sounddata\\saturn themes\\bgm\\wma\\advmilesS.adx");
		helperFunctions.ReplaceFile("system\\SoundData\\bgm\\wma\\tails.wma", "system\\sounddata\\saturn themes\\bgm\\wma\\tailsS.mp3");
		helperFunctions.ReplaceFile("system\\SoundData\\bgm\\wma\\themiles.wma", "system\\sounddata\\saturn themes\\bgm\\wma\\themilesS.adx");
	}

	if (SatThemeK)
	{
		helperFunctions.ReplaceFile("system\\SoundData\\bgm\\wma\\advknkls.wma", "system\\sounddata\\saturn themes\\bgm\\wma\\advknklsS.adx");
		helperFunctions.ReplaceFile("system\\SoundData\\bgm\\wma\\knuckles.wma", "system\\sounddata\\saturn themes\\bgm\\wma\\knucklesS.mp3");
		helperFunctions.ReplaceFile("system\\SoundData\\bgm\\wma\\theknkls.wma", "system\\sounddata\\saturn themes\\bgm\\wma\\theknklsS.mp3");
	}

	if (SatThemeA)
	{
		Soundtest_Theme[4].Name = "AMY: Miracle Blue ~Little Planet~";
		helperFunctions.ReplaceFile("system\\SoundData\\bgm\\wma\\advamy.wma", "system\\sounddata\\saturn themes\\bgm\\wma\\advamyS.adx");
		helperFunctions.ReplaceFile("system\\SoundData\\bgm\\wma\\amy.wma", "system\\sounddata\\saturn themes\\bgm\\wma\\amyS.mp3");
		helperFunctions.ReplaceFile("system\\SoundData\\bgm\\wma\\theamy.wma", "system\\sounddata\\saturn themes\\bgm\\wma\\theamyS.mp3");
	}

	if (SatThemeE)
	{
		helperFunctions.ReplaceFile("system\\SoundData\\bgm\\wma\\eggman.wma", "system\\sounddata\\saturn themes\\bgm\\wma\\eggmanS.adx");
	}

	if (SatThemeSS)
	{
		helperFunctions.ReplaceFile("system\\SoundData\\bgm\\wma\\sprsonic.wma", "system\\sounddata\\saturn themes\\bgm\\wma\\sprsonicS.adx");
	}

	if (SatThemeC)
	{
		helperFunctions.ReplaceFile("system\\SoundData\\bgm\\wma\\chao.wma", "system\\sounddata\\saturn themes\\bgm\\wma\\chaoS.adx");
	}

	if (MRMusic)
	{
		helperFunctions.ReplaceFile("system\\SoundData\\bgm\\wma\\titl_mr1.wma", "system\\sounddata\\bgm\\satmusic\\title_mr_sat.adx");
	}

	if (EGMusic)
	{
		helperFunctions.ReplaceFile("system\\SoundData\\bgm\\wma\\egcarer1.wma", "system\\sounddata\\bgm\\satmusic\\egcarersky_sat.adx");
		helperFunctions.ReplaceFile("system\\SoundData\\bgm\\wma\\egcarer2.wma", "system\\sounddata\\bgm\\satmusic\\egcarersea_sat.adx");
	}

	if (ECMusic)
	{
		helperFunctions.ReplaceFile("system\\SoundData\\bgm\\wma\\ecoast3.wma", "system\\sounddata\\bgm\\satmusic\\ecoast3_sat.adx");
		
		helperFunctions.ReplaceFile("system\\SoundData\\bgm\\wma\\finaleg1.wma", "system\\sounddata\\bgm\\satmusic\\finaleg1_sat.adx");
		helperFunctions.ReplaceFile("system\\SoundData\\bgm\\wma\\finaleg2.wma", "system\\sounddata\\bgm\\satmusic\\finaleg2_sat.adx");
	}

	if (WVMusic)
	{
        helperFunctions.ReplaceFile("system\\SoundData\\bgm\\wma\\wndyvly1.wma", "system\\sounddata\\bgm\\satmusic\\wvalley1_sat.adx");
		helperFunctions.ReplaceFile("system\\SoundData\\bgm\\wma\\wndyvly2.wma", "system\\sounddata\\bgm\\satmusic\\wvalley2_sat.adx");
		helperFunctions.ReplaceFile("system\\SoundData\\bgm\\wma\\wndyvly3.wma", "system\\sounddata\\bgm\\satmusic\\wvalley3_sat.adx");
	}

	if (CMusic)
	{
        helperFunctions.ReplaceFile("system\\SoundData\\bgm\\wma\\casino1.wma", "system\\sounddata\\bgm\\satmusic\\casino1_sat.adx");
		helperFunctions.ReplaceFile("system\\SoundData\\bgm\\wma\\casino2.wma", "system\\sounddata\\bgm\\satmusic\\casino2_sat.adx");
		helperFunctions.ReplaceFile("system\\SoundData\\bgm\\wma\\casino3.wma", "system\\sounddata\\bgm\\satmusic\\sonicpinballsat.adx");
	}

	if (ICMusic)
	{
		helperFunctions.ReplaceFile("system\\SoundData\\bgm\\wma\\icecap1.wma", "system\\sounddata\\bgm\\satmusic\\icecap1_sat.adx");
		helperFunctions.ReplaceFile("system\\SoundData\\bgm\\wma\\icecap2.wma", "system\\sounddata\\bgm\\satmusic\\icecap2_sat.adx");
		helperFunctions.ReplaceFile("system\\SoundData\\bgm\\wma\\icecap3.wma", "system\\sounddata\\bgm\\satmusic\\snowboard_sat.adx");
	}

	if (TPMusic)
	{
		helperFunctions.ReplaceFile("system\\SoundData\\bgm\\wma\\twnklpk1.wma", "system\\sounddata\\bgm\\satmusic\\twinkle1_sat.adx");
		helperFunctions.ReplaceFile("system\\SoundData\\bgm\\wma\\twnklpk3.wma", "system\\sounddata\\bgm\\satmusic\\twinkle3_sat.adx");
	}

	if (SHMusic)
	{
		helperFunctions.ReplaceFile("system\\SoundData\\bgm\\wma\\highway2.wma", "system\\sounddata\\bgm\\satmusic\\highway2_sat.mp3");
		helperFunctions.ReplaceFile("system\\SoundData\\bgm\\wma\\highway3.wma", "system\\sounddata\\bgm\\satmusic\\highway3_sat.adx");
	}

	if (RMMusic)
	{
		helperFunctions.ReplaceFile("system\\SoundData\\bgm\\wma\\redmntn1.wma", "system\\sounddata\\bgm\\satmusic\\redmount1_sat.adx");
		helperFunctions.ReplaceFile("system\\SoundData\\bgm\\wma\\redmntn2.wma", "system\\sounddata\\bgm\\satmusic\\redmount2_sat.adx");
	}

	if (SDMusic)
	{
		helperFunctions.ReplaceFile("system\\SoundData\\bgm\\wma\\skydeck1.wma", "system\\sounddata\\bgm\\satmusic\\deck1_sat.adx");
		helperFunctions.ReplaceFile("system\\SoundData\\bgm\\wma\\skydeck2.wma", "system\\sounddata\\bgm\\satmusic\\deck2_sat.adx");
	}

	if (HSMusic)
	{
		helperFunctions.ReplaceFile("system\\SoundData\\bgm\\wma\\shelter1.wma", "system\\sounddata\\bgm\\satmusic\\shelter1_sat.adx");
		helperFunctions.ReplaceFile("system\\SoundData\\bgm\\wma\\shelter2.wma", "system\\sounddata\\bgm\\satmusic\\shelter2_sat.adx");
	}

	if (LWMusic)
	{
		helperFunctions.ReplaceFile("system\\SoundData\\bgm\\wma\\lstwrld1.wma", "system\\sounddata\\bgm\\satmusic\\lostw1_sat.adx");
		helperFunctions.ReplaceFile("system\\SoundData\\bgm\\wma\\lstwrld2.wma", "system\\sounddata\\bgm\\satmusic\\lostw2_sat.adx");
		helperFunctions.ReplaceFile("system\\SoundData\\bgm\\wma\\lstwrld3.wma", "system\\sounddata\\bgm\\satmusic\\lostw3_sat.adx");
	}

	if (FEMusic)
	{
		helperFunctions.ReplaceFile("system\\SoundData\\bgm\\wma\\finaleg1.wma", "system\\sounddata\\bgm\\satmusic\\finaleg1_sat.adx");
		helperFunctions.ReplaceFile("system\\SoundData\\bgm\\wma\\finaleg2.wma", "system\\sounddata\\bgm\\satmusic\\finaleg2_sat.adx");
	}

	if (TCMusic)
	{
		helperFunctions.ReplaceFile("system\\SoundData\\bgm\\wma\\circuit.wma", "system\\sounddata\\bgm\\satmusic\\satcircuit.adx");
	}


	if (EVMusic)
	{
		helperFunctions.ReplaceFile("system\\SoundData\\bgm\\wma\\evtbgm01.wma", "system\\sounddata\\bgm\\satmusic\\strain_sat.adx");
		helperFunctions.ReplaceFile("system\\SoundData\\bgm\\wma\\evtbgm00.wma", "system\\sounddata\\bgm\\satmusic\\sadness_sat.adx");
		helperFunctions.ReplaceFile("system\\SoundData\\bgm\\wma\\evtbgm03.wma", "system\\sounddata\\bgm\\satmusic\\goodbye_sat.adx");
		helperFunctions.ReplaceFile("system\\SoundData\\bgm\\wma\\evtbgm04.wma", "system\\sounddata\\bgm\\satmusic\\thepast_sat.adx");

	}

	if (MenuMusic)
	{
		helperFunctions.ReplaceFile("system\\SoundData\\bgm\\wma\\option.wma", "system\\sounddata\\bgm\\satmusic\\option_sat.adx");
		helperFunctions.ReplaceFile("system\\SoundData\\bgm\\wma\\charactr.wma", "system\\sounddata\\bgm\\satmusic\\charselect_sat.adx");
		helperFunctions.ReplaceFile("system\\SoundData\\bgm\\wma\\trial.wma", "system\\sounddata\\bgm\\satmusic\\trial_sat.wma");
	}

	if (JMusic)
	{
		helperFunctions.ReplaceFile("system\\SoundData\\bgm\\wma\\MCLEAR_44.wma", "system\\sounddata\\bgm\\satmusic\\MCLEAR_SAT.mp3");
		helperFunctions.ReplaceFile("system\\SoundData\\bgm\\wma\\MSTART_44.wma", "system\\sounddata\\bgm\\satmusic\\MSTART_SAT.mp3");
		helperFunctions.ReplaceFile("system\\SoundData\\bgm\\wma\\speedup.wma", "system\\sounddata\\bgm\\satmusic\\speedsat.mp3");
		helperFunctions.ReplaceFile("system\\SoundData\\bgm\\wma\\timer.wma", "system\\sounddata\\bgm\\satmusic\\drowningsat.mp3");
		helperFunctions.ReplaceFile("system\\SoundData\\bgm\\wma\\invncibl.wma", "system\\sounddata\\bgm\\satmusic\\invincisat.mp3");
		helperFunctions.ReplaceFile("system\\SoundData\\bgm\\wma\\rndclear.wma", "system\\sounddata\\bgm\\satmusic\\victory_sat.wma");
		helperFunctions.ReplaceFile("system\\SoundData\\bgm\\wma\\continue.wma", "system\\sounddata\\bgm\\satmusic\\continue_sat.wma");

	}

	if (BMusic)
	{
		helperFunctions.ReplaceFile("system\\SoundData\\bgm\\wma\\bossall.wma", "system\\sounddata\\bgm\\satmusic\\bossall_sat.adx");
		helperFunctions.ReplaceFile("system\\SoundData\\bgm\\wma\\bossevnt.wma", "system\\sounddata\\bgm\\satmusic\\charboss_sat.mp3");
		helperFunctions.ReplaceFile("system\\SoundData\\bgm\\wma\\chaos_p2.wma", "system\\sounddata\\bgm\\satmusic\\chaos_p2_sat.adx");
		helperFunctions.ReplaceFile("system\\SoundData\\bgm\\wma\\chaos.wma", "system\\sounddata\\bgm\\satmusic\\chaos_sat.adx");
		helperFunctions.ReplaceFile("system\\SoundData\\bgm\\wma\\eggmbl23.wma", "system\\sounddata\\bgm\\satmusic\\finalboss_sat.adx");
	}

	if (SA1SSFX)
	{
        helperFunctions.ReplaceFile("system\\SoundData\\SE\\P_SONICTAILS_BANK03.dat", "system\\sounddata\\se_sat\\P_SONICTAILS_BANK03_SAT.dat");
		helperFunctions.ReplaceFile("system\\SoundData\\SE\\V_SONICTAILS_E_BANK06.dat", "system\\sounddata\\se_sat\\V_SONICTAILS_E_BANK06_SAT.dat");
		helperFunctions.ReplaceFile("system\\SoundData\\SE\\P_KNUCKLES_BANK03.dat", "system\\sounddata\\se_sat\\P_KNUCKLES_BANK03_SAT.dat");
		helperFunctions.ReplaceFile("system\\SoundData\\SE\\P_METALTAILS_BANK03.dat", "system\\sounddata\\se_sat\\P_METALTAILS_BANK03_SAT.dat");
		helperFunctions.ReplaceFile("system\\SoundData\\SE\\COMMON_BANK00.dat", "system\\sounddata\\se_sat\\COMMON_BANK00_SAT.dat");
		helperFunctions.ReplaceFile("system\\SoundData\\SE\\check_sheet_bank02.dat", "system\\sounddata\\se_sat\\check_sheet_bank02_SAT.dat");

	}

	std::wstring modPathString(path, path + strlen(path)); 

	//Stage Configs
	if (SatEmeraldCoast)
	{
		LoadSaturnEXE(L"beach_data", modPathString, helperFunctions);
		ReplacePVM("BEACH01", "BEACH01_SAT");
		ReplacePVM("BEACH01_DC", "BEACH01_DC_SAT");
		ReplacePVM("BEACH02", "BEACH02_SAT");
		ReplacePVM("BEACH02_DC", "BEACH02_DC_SAT");
		ReplacePVM("BEACH03", "BEACH03_SAT");
		ReplacePVM("BEACH03_DC", "BEACH03_DC_SAT");
		ReplacePVM("BG_BEACH", "BG_BEACH_SAT");
		ReplacePVM("BG_BEACH_DC", "BG_BEACH_DC_SAT");
		ReplacePVM("OBJ_BEACH", "OBJ_BEACH_SAT");
		ReplacePVM("OBJ_BEACH_DC", "OBJ_BEACH_DC_SAT");
	}

	if (SatSpeedHighway)
	{
		helperFunctions.ReplaceFile("system\\PL_42B.BIN", "system\\PL_42B_SAT.BIN");
		ReplacePVM("HIGHWAY01", "HIGHWAY01_SAT");
		ReplacePVM("HIGHWAY02", "HIGHWAY02_SAT");
		ReplacePVM("HIGHWAY03", "HIGHWAY03_SAT");
		ReplacePVM("HIGHWAY01_DC", "HIGHWAY01_DC_SAT");
		ReplacePVM("HIGHWAY02_DC", "HIGHWAY02_DC_SAT");
		ReplacePVM("HIGHWAY03_DC", "HIGHWAY03_DC_SAT");
		ReplacePVM("BG_HIGHWAY", "BG_HIGHWAY_SAT");
		ReplacePVM("BG_HIGHWAY_DC", "BG_HIGHWAY_DC_SAT");
		ReplacePVM("BG_HIGHWAY02", "BG_HIGHWAY02_SAT");
		ReplacePVM("OBJ_HIGHWAY", "OBJ_HIGHWAY_SAT");
		ReplacePVM("OBJ_HIGHWAY_DC", "OBJ_HIGHWAY_DC_SAT");
		ReplacePVM("OBJ_HIGHWAY2", "OBJ_HIGHWAY2_SAT");
		ReplacePVM("OBJ_HIGHWAY2_DC", "OBJ_HIGHWAY2_DC_SAT");
	}


	if (SatRedMountain)
	{
		INIT_SaturnRM_DX();
		helperFunctions.ReplaceFile("system\\data\\stg05_mountain\\landtable0501.c.sa1lvl", "system\\data\\stg05_mountain\\RedMountain2SAT_Landtable_DC.sa1lvl");
		helperFunctions.ReplaceFile("system\\PL_50B.BIN", "system\\PL_50B_SAT.BIN");
		helperFunctions.ReplaceFile("system\\PL_51B.BIN", "system\\PL_51B_SAT.BIN");
		ReplacePVM("MOUNTAIN01", "MOUNTAIN01_SAT");
		ReplacePVM("MOUNTAIN01_DC", "MOUNTAIN01_DC_SAT");
		ReplacePVM("MOUNTAIN02", "MOUNTAIN02_SAT");
		ReplacePVM("MOUNTAIN02_DC", "MOUNTAIN02_DC_SAT");
		ReplacePVM("MOUNTAIN03", "MOUNTAIN03_SAT");
		ReplacePVM("MOUNTAIN03_DC", "MOUNTAIN03_DC_SAT");
		ReplacePVM("OBJ_MOUNTAIN", "OBJ_MOUNTAIN_SAT");
		ReplacePVM("OBJ_MOUNTAIN_DC", "OBJ_MOUNTAIN_DC_SAT");
	}

	if (SatSSChaoGar)
	{
		ReplacePVM("AL_DX_OBJ_CMN", "AL_DX_OBJ_CMN_SAT");
		ReplacePVM("GARDEN00SS", "GARDEN00SS_SAT");
		ReplacePVM("CHAO_OBJECT_DC", "CHAO_OBJECT_DC_SAT");
		ReplacePVM("GARDEN00_DC", "GARDEN00_DC_SAT");
	}

	if (SatECChaoGar)
	{
		ReplacePVM("AL_DX_OBJ_CMN", "AL_DX_OBJ_CMN_SAT");
		ReplacePVM("CHAO_OBJECT_DC", "CHAO_OBJECT_DC_SAT");
		ReplacePVM("GARDEN01_DC", "GARDEN01_DC_SAT");
		ReplacePVM("GARDEN01EC", "GARDEN01EC_SAT");
	}

	if (StationSquare)
	{
		ReplacePVM("ADVSS00", "ADVSS00_SAT");
		ReplacePVM("ADVSS00_DC", "ADVSS00_DC_SAT");
		ReplacePVM("ADVSS01", "ADVSS01_SAT");
		ReplacePVM("ADVSS01_DC", "ADVSS01_DC_SAT");
		ReplacePVM("ADVSS03", "ADVSS03_SAT");
		ReplacePVM("ADVSS03_DC", "ADVSS03_DC_SAT");
		ReplacePVM("ADVSS04", "ADVSS04_SAT");
		ReplacePVM("ADVSS04_DC", "ADVSS04_DC_SAT");
		ReplacePVM("LM_CHAOS0", "LM_CHAOS0_SAT");
		ReplacePVM("LM_CHAOS0_DC", "LM_CHAOS0_DC_SAT");
		ReplacePVM("EGM2_TIKEI", "EGM2_TIKEI_SAT");
		ReplacePVM("EGM2_TIKEI_DC", "EGM2_TIKEI_DC_SAT");


	}


	if (SaturnEgg)
	{
		LoadSaturnEXE(L"Eggman_data", modPathString, helperFunctions);
		std::string fullPath = path + (std::string)"\\system\\egg_welds.ini";
		helperFunctions.RegisterCharacterWelds(Characters_Eggman, fullPath.c_str());//for char eggman's ini welds
		InitEggmobilenWeldInfo_r();
		ReplacePVM("CHAOS6_EGGMAN", "CHAOS6_EGGMAN_SAT");
		ReplacePVM("CHAOS6_EGGMAN_DC", "CHAOS6_EGGMAN_DC_SAT");
		ReplacePVM("EGGMAN", "EGGMAN_SAT");
		ReplacePVM("CHAOS6_EGGMAN", "CHAOS6_EGGMAN_SAT");
		ReplacePVM("EGM1EGGMAN", "EGM1EGGMAN_SAT");
		ReplacePVM("EGM1EGGMAN_DC", "EGM1EGGMAN_DC_SAT");
		ReplacePVM("EGM2_COMMON", "EGM2_COMMON_SAT");
		ReplacePVM("EGM2_COMMON_DC", "EGM2_COMMON_DC_SAT");
		ReplacePVM("MRACE_EGGMOBLE", "MRACE_EGGMOBLE_SAT");
		ReplacePVM("MRACE_EGGMOBLE_DC", "MRACE_EGGMOBLE_DC_SAT");
		ReplacePVM("EV_EGGMAN_BODY", "EV_EGGMAN_BODY_SAT");
		ReplacePVM("EV_EGGMAN_BODY_DC", "EV_EGGMAN_BODY_DC_SAT");
		ReplacePVM("EV_EGGMOBLE0", "EV_EGGMOBLE0_SAT");
		ReplacePVM("EV_EGGMOBLE0_DC", "EV_EGGMOBLE0_DC_SAT");
		ReplacePVM("EGM3MDL", "EGM3MDL_SAT");
		ReplacePVM("EGM3MDL_DC", "EGM3MDL_DC_SAT");
	}

	if (SaturnMetalSonic)
	{
		LoadSaturnDLL(L"chrmodels_metal", modPathString, helperFunctions);
		ReplacePVM("METALSONIC", "METALSONK_SAT");
	}

	if (SaturnTikal)
	{
		ReplacePVM("TIKAL", "TIKAL_SAT");
		LoadSaturnEXE(L"tikal_data", modPathString, helperFunctions);
		std::string fullPath = path + (std::string)"\\system\\tk_welds.ini";
		helperFunctions.RegisterCharacterWelds(Characters_Tikal, fullPath.c_str());
		
	}

	if (SaturnBig == SBig || SaturnBig == SBigLE || SaturnBig == SPBig)
	{
		UpgradeChecks(path, helperFunctions);
		LoadSaturnDLL(L"chrmodels_big", modPathString, helperFunctions);
		std::string fullpath = path + (std::string)"\\system\\bg_welds.ini";
		helperFunctions.RegisterCharacterWelds(Characters_Big, fullpath.c_str());
		switch (SaturnBig)
		{
		case SBig:
			ReplacePVM("BIG", "BIG_SAT");
				break;
		case SBigLE:
			ReplacePVM("BIG", "BIG_SAT_LOW");
				break;
		case SPBig:
			LoadSaturnDLL(L"chrmodels_big_proto", modPathString, helperFunctions);
			std::string fullPath = path + (std::string)"\\system\\bg_welds_proto.ini";
			helperFunctions.RegisterCharacterWelds(Characters_Big, fullPath.c_str());
			ReplacePVM("BIG", "BIG_PROTO_SAT");
			break;
		}
	}

	if (SaturnBadniks)
	{
		LoadSaturnEXE(L"motobug_data", modPathString, helperFunctions);
		ReplacePVM("E_SAI", "E_SAI_SAT");
		ReplacePVM("E_SAI_DC", "E_SAI_DC_SAT");
		ReplacePVM("E_SARU", "E_SARU_SAT");
		ReplacePVM("E_SARU_DC", "E_SARU_DC_SAT");
	}

	if (Mal)
	{
		LoadSaturnDLL(L"mal_data", modPathString, helperFunctions);
		ReplacePVM("SS_PEOPLE", "MAL");
		ReplacePVM("SS_PEOPLE_DC", "MAL_DC");
	}



	if (GUISAT)
	{
		
		PVR_GUI(path, helperFunctions);
		
		ReplaceTex("FISHING", "hyouji_g", "GUI_SAT", "HUDgrams", 361007, 16, 16);
		ReplaceTex("FISHING", "bighyouji", "GUI_SAT", "BigHUD", 361006, 94, 57);
		ReplaceTex("CON_REGULAR_E", "hyoji_head", "GUI_SAT", "RegHUD", 931, 64, 64);
		ReplaceTex("BOARD_SCORE", "st_064s_score", "GUI_SAT","HUDPlusScore", 310000, 64, 32);
		ReplaceTex("OBJ_REGULAR", "item_speed", "GUI_SAT", "speedup", 4035, 64, 64);
		ReplaceTex("OBJ_REGULAR", "item_muteki", "GUI_SAT", "invisparkle", 4073, 64, 64);
		ReplaceTex("OBJ_MINI_CART", "hyoji_head_cart", "GUI_SAT", "timebest", 324043, 64, 64);
	}

	if (TGUISAT)
	{
		ReplaceTex("MILESRACE", "tailsplay_bg", "GUI_SAT", "racebar", 982, 236, 47);
		ReplaceTex("MILESRACE", "youwin0", "GUI_SAT", "youwin0c", 800, 727, 1480);
		ReplaceTex("MILESRACE", "youwin1", "GUI_SAT", "youwin1c", 801, 697, 1480);
		ReplaceTex("MILESRACE", "youwin2", "GUI_SAT", "youwin2c", 802, 735, 1480);
		ReplaceTex("MILESRACE", "youwin3", "GUI_SAT", "youwin3c", 803, 689, 1480);
		ReplaceTex("MILESRACE", "youlose0", "GUI_SAT", "youlose0b", 804, 99, 109);
		ReplaceTex("MILESRACE", "youlose1", "GUI_SAT", "youlose1b", 805, 101, 109);
		ReplaceTex("MILESRACE", "youlose2", "GUI_SAT", "youlose2b", 806, 100, 109);
		ReplaceTex("MILESRACE", "youlose3", "GUI_SAT", "youlose3b", 807, 100, 109);
	}

	if (RGUISAT)
	{
		ReplacePVM("SCORE_ACT_E", "SCORE_ACT_E_SAT");
		ReplacePVM("SCORE_ACT_E_DC", "SCORE_ACT_E_DC_SAT");
		ReplacePVM("SCORE_BACK", "SCORE_BACK_SAT");
		ReplacePVM("SCORE_BACK_DC", "SCORE_BACK_DC_SAT");
		ReplacePVM("SCORE_BOSS_E", "SCORE_BOSS_E_SAT");
		ReplacePVM("SCORE_BOSS_E_DC", "SCORE_BOSS_E_DC_SAT");
		ReplacePVM("SCORE_CART_E", "SCORE_CART_E_SAT");
		ReplacePVM("SCORE_CART_E_DC", "SCORE_CART_E_DC_SAT");
		ReplacePVM("SCORE_SHOOT_E", "SCORE_SHOOT_E_SAT");
		ReplacePVM("SCORE_SHOOT_E_DC", "SCORE_SHOOT_E_DC_SAT");
	}

	if (LifeSAT)
	{
		PVR_EMBLEM(path, helperFunctions);
		ReplaceTex("MILESRACE", "eggman_casol", "GUI_SAT", "eggrace", 365774, 256, 256);
		ReplaceTex("MILESRACE", "tailsplay_sonic", "GUI_SAT", "sonicrace", 983, 256, 256);
		ReplaceTex("MILESRACE", "tailsplay_tails", "GUI_SAT", "tailsrace", 984, 256, 256);
		ReplaceTex("CON_REGULAR_E", "hyoji_zanki_s", "GUI_SAT", "lifesonic", 951, 128, 128);
		ReplaceTex("CON_REGULAR_E", "hyoji_zanki_t", "GUI_SAT", "lifetails", 952, 128, 128);
		ReplaceTex("CON_REGULAR_E", "hyoji_zanki_k", "GUI_SAT", "lifeknuck", 953, 128, 128);
		ReplaceTex("CON_REGULAR_E", "hyoji_zanki_a", "GUI_SAT", "lifeamy", 999002, 128, 128);
		ReplaceTex("CON_REGULAR_E", "metal_zanki", "GUI_SAT", "lifemetal", 710227, 1280, 1280);
		ReplaceTex("SUPERSONIC_EXTRA", "hyoji_zanki_ss", "GUI_SAT", "lifesuper", 6243767, 128, 128);
		ReplaceTex("SUPERSONIC_EXTRA", "1upsuper", "GUI_SAT", "extrasuper", 6544685, 128, 128);
		ReplaceTex("OBJ_REGULAR", "item_1up", "GUI_SAT", "extrasonic", 4031, 64, 64);
		ReplaceTex("OBJ_REGULAR", "1upknuck", "GUI_SAT", "extraknuck", 4000, 64, 64);
		ReplaceTex("OBJ_REGULAR", "1uptails", "GUI_SAT", "extratails", 4004, 64, 64);
		ReplaceTex("OBJ_REGULAR", "1upamy", "GUI_SAT", "extraamy", 4001, 64, 64);
		ReplaceTex("OBJ_REGULAR", "1upmetal", "GUI_SAT", "extrametal", 710226, 64, 64);
		ReplaceTex("EMBLEM", "sonic_emblm01", "GUI_SAT", "af_emblemsonic", 4270, 64, 64);
		ReplacePVM("MilesCursor", "MilesCursor_SAT");
	}

	
	if (LifeSAT && SaturnBig == SBig || LifeSAT && SaturnBig == SBigLE || LifeSAT && SaturnBig == SPBig)
	{
		switch (SaturnBig)
		{
		case SBig:
			ReplaceTex("OBJ_REGULAR", "1upbig", "GUI_SATBIG", "extrabig", 4002, 64, 64);
			ReplaceTex("CON_REGULAR_E", "hyoji_zankib", "GUI_SATBIG", "lifebig", 1960010, 128, 128);
			break;
		case SBigLE:
			ReplaceTex("OBJ_REGULAR", "1upbig", "GUI_SATBIGL", "extrabigLE", 4002, 64, 64);
			ReplaceTex("CON_REGULAR_E", "hyoji_zankib", "GUI_SATBIGL", "lifebigLE", 1960010, 128, 128);
			break;
		case SPBig:
			ReplaceTex("OBJ_REGULAR", "1upbig", "GUI_SATBPROTO", "extrabigP", 4002, 64, 64);
			ReplaceTex("CON_REGULAR_E", "hyoji_zankib", "GUI_SATBPROTO", "lifebigP", 1960010, 128, 128);
			break;
		}
	}
	
	if (FontSAT)
	{
		ReplaceTex("CON_REGULAR_E", "snum_0", "GUI_SATFONT", "zero", 920, 64, 64);
		ReplaceTex("CON_REGULAR_E", "snum_1", "GUI_SATFONT", "one", 921, 64, 64);
		ReplaceTex("CON_REGULAR_E", "snum_2", "GUI_SATFONT", "two", 922, 64, 64);
		ReplaceTex("CON_REGULAR_E", "snum_3", "GUI_SATFONT", "three", 923, 64, 64);
		ReplaceTex("CON_REGULAR_E", "snum_4", "GUI_SATFONT", "four", 924, 64, 64);
		ReplaceTex("CON_REGULAR_E", "snum_5", "GUI_SATFONT", "five", 925, 64, 64);
		ReplaceTex("CON_REGULAR_E", "snum_6", "GUI_SATFONT", "six", 926, 64, 64);
		ReplaceTex("CON_REGULAR_E", "snum_7", "GUI_SATFONT", "seven", 927, 64, 64);
		ReplaceTex("CON_REGULAR_E", "snum_8", "GUI_SATFONT", "eight", 928, 64, 64);
		ReplaceTex("CON_REGULAR_E", "snum_9", "GUI_SATFONT", "nine", 929, 64, 64);
		ReplaceTex("CON_REGULAR_E", "snum_co", "GUI_SATFONT", "colon", 930, 32, 32);
	}

	if (MenuSAT)
	{
		ReplacePVM("AVA_BACK", "AVA_BACK_SAT");
		ReplacePVM("AVA_BACK_DC", "AVA_BACK_SAT");
		ReplacePVM("AVA_OPTION_E", "AVA_OPTION_E_SAT");
		ReplacePVM("AVA_OPTION_E_DC", "AVA_OPTION_E_DC_SAT");
		ReplaceTex("AVA_EMBLEM", "embrem", "GUI_SAT", "emblemressat", 365343, 64, 64);
		ReplaceTex("AVA_EMBLEM", "metal_emblem", "GUI_SAT", "memblemressat", 100001010, 64, 64);
	}

	if (SaturnBrand)
	{
		ReplacePVM("AVA_GTITLE0_E", "AVA_GTITLE0_E_SAT");
		ReplacePVM("AVA_GTITLE0_DC_HD", "AVA_GTITLE0_DC_HD_SAT");
		ReplaceTex("AVA_TITLE_CMN", "sonic_00", "SADX_TITLE_SONK_SAT", "satsonk", 3489661211, 1024, 1024);
		ReplaceTex("AVA_TITLE_CMN", "sonic_01", "SADX_TITLE_SONK_SAT", "blank1", 3489661212, 256, 256);
		ReplaceTex("AVA_TITLE_CMN", "sonic_02", "SADX_TITLE_SONK_SAT", "blank2", 3489661213, 256, 256);
		ReplaceTex("AVA_TITLE_CMN", "sonic_05", "SADX_TITLE_SONK_SAT", "blank3", 3489661214, 256, 256);
		ReplaceTex("AVA_TITLE_CMN", "sonic_06", "SADX_TITLE_SONK_SAT", "blank4", 3489661217, 256, 256);
		ReplaceTex("AVA_TITLE_CMN", "sonic_08", "SADX_TITLE_SONK_SAT", "blank5", 3489661216, 256, 256);
		ReplaceTex("AVA_TITLE_CMN", "sonic_09", "SADX_TITLE_SONK_SAT", "blank6", 3489661217, 256, 256);
		ReplaceTex("AVA_TITLE_CMN", "sonic_10", "SADX_TITLE_SONK_SAT", "blank7", 3489661218, 256, 256);
		ReplaceTex("AVA_TITLE_CMN", "sonic_11", "SADX_TITLE_SONK_SAT", "blank8", 3489661219, 256, 256);
		ReplaceTex("AVA_TITLE_CMN", "sonic_12", "SADX_TITLE_SONK_SAT", "blank9", 3489661220, 256, 256);
		ReplaceTex("AVA_TITLE_CMN", "sonic_13", "SADX_TITLE_SONK_SAT", "blank10", 3489661221, 256, 256);
		ReplaceTex("AVA_TITLE_CMN", "sonic_14", "SADX_TITLE_SONK_SAT", "blank11", 3489661222, 256, 256);
		ReplaceTex("AVA_TITLE_CMN", "sonic_15", "SADX_TITLE_SONK_SAT", "blank12", 3489661223, 256, 256);
		ReplaceTex("AVA_TITLE_BACK_E", "title_back_e0", "SADX_MENU_BACK_SAT", "satretro1", 100000180, 256, 256);
		ReplaceTex("AVA_TITLE_BACK_E", "title_back_e1", "SADX_MENU_BACK_SAT", "satretro2", 100000181, 256, 256);
		ReplaceTex("AVA_TITLE_BACK_E", "title_back_e2", "SADX_MENU_BACK_SAT", "satretro3", 100000182, 256, 256);
		ReplaceTex("AVA_TITLE_BACK_E", "title_back_e3", "SADX_MENU_BACK_SAT", "satretro4", 100000183, 256, 256);
		ReplaceTex("AVA_TITLE_BACK_E", "title_back_e4", "SADX_MENU_BACK_SAT", "satretro5", 100000184, 128, 128);
		ReplaceTex("AVA_TITLE_BACK_E", "title_back_e5", "SADX_MENU_BACK_SAT", "satretro6", 100000185, 128, 128);
		ReplaceTex("AVA_TITLE_BACK_E", "title_back_e6", "SADX_MENU_BACK_SAT", "satretro7", 100000186, 128, 128);
		ReplaceTex("AVA_TITLE_BACK_E", "title_back_e7", "SADX_MENU_BACK_SAT", "satretro8", 100000187, 128, 128);
	}

	if (JamSpring)
	{
		Init_Springs();
		ReplaceTex("OBJ_REGULAR", "bane_a", "SAT_ITEMS", "satspring", 4006, 32, 32);
	}

	if (Monitor)
	{
		Init_Monitor();
		ReplaceTex("OBJ_REGULAR", "kaiho_gray", "SAT_ITEMS", "itemmonitor", 44, 32, 32);
	}

	if (JamAnim)
	{
		LoadSaturnDLL(L"jamanim_data", modPathString, helperFunctions);
	}

	if (TitleCards)
	{
		PVR_TitleCards(path, helperFunctions);
	}

	WriteCall((void*)0x491701, PlaySonicIdleVoice_r);
}
