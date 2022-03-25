#pragma once

/*------------------------------------------------------------------------
 * User specifiable definitions
 *------------------------------------------------------------------------*/

/* 
 Default error level applied when a user did not specify an error level 

 Possible values:
    5 : 5% error level
    4 : 4% error level
    3 : 3% error level
    2 : 2% error level
    1 : 1% error level
*/
#define DEFAULT_ERROR_LEVEL "5"

/*------------------------------------------------------------------------
 * IDEA's version number
 *------------------------------------------------------------------------*/

#define IDEA_VER_MAJOR 0
#define IDEA_VER_MINOR 0
#define IDEA_VER_SUBMINOR 0

/*------------------------------------------------------------------------
 * Function prototypes
 *------------------------------------------------------------------------*/

#ifdef _WINDLL
#define IDEA_API(type) __declspec(dllexport) type
#else
#define IDEA_API(type) type
#endif

#ifdef __cplusplus
extern "C" {
#endif

IDEA_API(const char*) IDEA_Init(const char* modeldir, const char* errlev);
IDEA_API(const char*) IDEA_Finalize(void);
IDEA_API(const char*) IDEA_Units(void);

IDEA_API(double) IDEA_DEP(const double D, const double E);
IDEA_API(double) IDEA_DET(const double D, const double E);
IDEA_API(double) IDEA_DEH(const double D, const double E);
IDEA_API(double) IDEA_DES(const double D, const double E);
IDEA_API(double) IDEA_DEA(const double D, const double E);
IDEA_API(double) IDEA_DEC(const double D, const double E);
IDEA_API(double) IDEA_DEG(const double D, const double E);
IDEA_API(double) IDEA_DEV(const double D, const double E);
IDEA_API(double) IDEA_DEK(const double D, const double E);

IDEA_API(double) IDEA_PTD(const double P, const double T);
IDEA_API(double) IDEA_PTE(const double P, const double T);
IDEA_API(double) IDEA_PTH(const double P, const double T);
IDEA_API(double) IDEA_PTS(const double P, const double T);
IDEA_API(double) IDEA_PTA(const double P, const double T);
IDEA_API(double) IDEA_PTC(const double P, const double T);
IDEA_API(double) IDEA_PTG(const double P, const double T);
IDEA_API(double) IDEA_PTV(const double P, const double T);
IDEA_API(double) IDEA_PTK(const double P, const double T);

IDEA_API(double) IDEA_DPT(const double D, const double P);
IDEA_API(double) IDEA_DPE(const double D, const double P);

IDEA_API(void) IDEA_DEP_Grad(double* diff, const double D, const double E);
IDEA_API(void) IDEA_DET_Grad(double* diff, const double D, const double E);
IDEA_API(void) IDEA_DEH_Grad(double* diff, const double D, const double E);
IDEA_API(void) IDEA_DES_Grad(double* diff, const double D, const double E);
IDEA_API(void) IDEA_DEA_Grad(double* diff, const double D, const double E);
IDEA_API(void) IDEA_DEC_Grad(double* diff, const double D, const double E);
IDEA_API(void) IDEA_DEG_Grad(double* diff, const double D, const double E);
IDEA_API(void) IDEA_DEV_Grad(double* diff, const double D, const double E);
IDEA_API(void) IDEA_DEK_Grad(double* diff, const double D, const double E);

IDEA_API(void) IDEA_PTD_Grad(double* diff, const double P, const double T);
IDEA_API(void) IDEA_PTE_Grad(double* diff, const double P, const double T);
IDEA_API(void) IDEA_PTH_Grad(double* diff, const double P, const double T);
IDEA_API(void) IDEA_PTS_Grad(double* diff, const double P, const double T);
IDEA_API(void) IDEA_PTA_Grad(double* diff, const double P, const double T);
IDEA_API(void) IDEA_PTC_Grad(double* diff, const double P, const double T);
IDEA_API(void) IDEA_PTG_Grad(double* diff, const double P, const double T);
IDEA_API(void) IDEA_PTV_Grad(double* diff, const double P, const double T);
IDEA_API(void) IDEA_PTK_Grad(double* diff, const double P, const double T);

IDEA_API(void) IDEA_DPT_Grad(double* diff, const double D, const double P);
IDEA_API(void) IDEA_DPE_Grad(double* diff, const double D, const double P);

#ifdef __cplusplus
}
#endif