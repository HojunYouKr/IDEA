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

IDEA_API(double) DEP_ANN(const double D, const double E);
IDEA_API(double) DET_ANN(const double D, const double E);
IDEA_API(double) DEH_ANN(const double D, const double E);
IDEA_API(double) DES_ANN(const double D, const double E);
IDEA_API(double) DEA_ANN(const double D, const double E);
IDEA_API(double) DEC_ANN(const double D, const double E);
IDEA_API(double) DEG_ANN(const double D, const double E);
IDEA_API(double) DEV_ANN(const double D, const double E);
IDEA_API(double) DEK_ANN(const double D, const double E);

IDEA_API(double) PTD_ANN(const double P, const double T);
IDEA_API(double) PTE_ANN(const double P, const double T);
IDEA_API(double) PTH_ANN(const double P, const double T);
IDEA_API(double) PTS_ANN(const double P, const double T);
IDEA_API(double) PTA_ANN(const double P, const double T);
IDEA_API(double) PTC_ANN(const double P, const double T);
IDEA_API(double) PTG_ANN(const double P, const double T);
IDEA_API(double) PTV_ANN(const double P, const double T);
IDEA_API(double) PTK_ANN(const double P, const double T);

IDEA_API(double) DPT_ANN(const double D, const double P);
IDEA_API(double) DPE_ANN(const double D, const double P);

IDEA_API(void) DEP_diff_ANN(double* diff, const double D, const double E);
IDEA_API(void) DET_diff_ANN(double* diff, const double D, const double E);
IDEA_API(void) DEH_diff_ANN(double* diff, const double D, const double E);
IDEA_API(void) DES_diff_ANN(double* diff, const double D, const double E);
IDEA_API(void) DEA_diff_ANN(double* diff, const double D, const double E);
IDEA_API(void) DEC_diff_ANN(double* diff, const double D, const double E);
IDEA_API(void) DEG_diff_ANN(double* diff, const double D, const double E);
IDEA_API(void) DEV_diff_ANN(double* diff, const double D, const double E);
IDEA_API(void) DEK_diff_ANN(double* diff, const double D, const double E);

IDEA_API(void) PTD_diff_ANN(double* diff, const double P, const double T);
IDEA_API(void) PTE_diff_ANN(double* diff, const double P, const double T);
IDEA_API(void) PTH_diff_ANN(double* diff, const double P, const double T);
IDEA_API(void) PTS_diff_ANN(double* diff, const double P, const double T);
IDEA_API(void) PTA_diff_ANN(double* diff, const double P, const double T);
IDEA_API(void) PTC_diff_ANN(double* diff, const double P, const double T);
IDEA_API(void) PTG_diff_ANN(double* diff, const double P, const double T);
IDEA_API(void) PTV_diff_ANN(double* diff, const double P, const double T);
IDEA_API(void) PTK_diff_ANN(double* diff, const double P, const double T);

IDEA_API(void) DPT_diff_ANN(double* diff, const double D, const double P);
IDEA_API(void) DPE_diff_ANN(double* diff, const double D, const double P);

#ifdef __cplusplus
}
#endif