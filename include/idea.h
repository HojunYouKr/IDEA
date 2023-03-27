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

#define IDEA_VER_MAJOR 1
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

IDEA_API(double) IDEA_DEP_Grad(double* grad, const double D, const double E);
IDEA_API(double) IDEA_DET_Grad(double* grad, const double D, const double E);
IDEA_API(double) IDEA_DEH_Grad(double* grad, const double D, const double E);
IDEA_API(double) IDEA_DES_Grad(double* grad, const double D, const double E);
IDEA_API(double) IDEA_DEA_Grad(double* grad, const double D, const double E);
IDEA_API(double) IDEA_DEC_Grad(double* grad, const double D, const double E);
IDEA_API(double) IDEA_DEG_Grad(double* grad, const double D, const double E);
IDEA_API(double) IDEA_DEV_Grad(double* grad, const double D, const double E);
IDEA_API(double) IDEA_DEK_Grad(double* grad, const double D, const double E);

IDEA_API(double) IDEA_PTD_Grad(double* grad, const double P, const double T);
IDEA_API(double) IDEA_PTE_Grad(double* grad, const double P, const double T);
IDEA_API(double) IDEA_PTH_Grad(double* grad, const double P, const double T);
IDEA_API(double) IDEA_PTS_Grad(double* grad, const double P, const double T);
IDEA_API(double) IDEA_PTA_Grad(double* grad, const double P, const double T);
IDEA_API(double) IDEA_PTC_Grad(double* grad, const double P, const double T);
IDEA_API(double) IDEA_PTG_Grad(double* grad, const double P, const double T);
IDEA_API(double) IDEA_PTV_Grad(double* grad, const double P, const double T);
IDEA_API(double) IDEA_PTK_Grad(double* grad, const double P, const double T);

IDEA_API(double) IDEA_DPT_Grad(double* grad, const double D, const double P);
IDEA_API(double) IDEA_DPE_Grad(double* grad, const double D, const double P);

IDEA_API(double)
IDEA_DEP_Hess(double* hess, double* grad, const double D, const double E);
IDEA_API(double)
IDEA_DET_Hess(double* hess, double* grad, const double D, const double E);
IDEA_API(double)
IDEA_DEH_Hess(double* hess, double* grad, const double D, const double E);
IDEA_API(double)
IDEA_DES_Hess(double* hess, double* grad, const double D, const double E);
IDEA_API(double)
IDEA_DEA_Hess(double* hess, double* grad, const double D, const double E);
IDEA_API(double)
IDEA_DEC_Hess(double* hess, double* grad, const double D, const double E);
IDEA_API(double)
IDEA_DEG_Hess(double* hess, double* grad, const double D, const double E);
IDEA_API(double)
IDEA_DEV_Hess(double* hess, double* grad, const double D, const double E);
IDEA_API(double)
IDEA_DEK_Hess(double* hess, double* grad, const double D, const double E);

IDEA_API(double)
IDEA_PTD_Hess(double* hess, double* grad, const double P, const double T);
IDEA_API(double)
IDEA_PTE_Hess(double* hess, double* grad, const double P, const double T);
IDEA_API(double)
IDEA_PTH_Hess(double* hess, double* grad, const double P, const double T);
IDEA_API(double)
IDEA_PTS_Hess(double* hess, double* grad, const double P, const double T);
IDEA_API(double)
IDEA_PTA_Hess(double* hess, double* grad, const double P, const double T);
IDEA_API(double)
IDEA_PTC_Hess(double* hess, double* grad, const double P, const double T);
IDEA_API(double)
IDEA_PTG_Hess(double* hess, double* grad, const double P, const double T);
IDEA_API(double)
IDEA_PTV_Hess(double* hess, double* grad, const double P, const double T);
IDEA_API(double)
IDEA_PTK_Hess(double* hess, double* grad, const double P, const double T);

IDEA_API(double)
IDEA_DPT_Hess(double* hess, double* grad, const double D, const double P);
IDEA_API(double)
IDEA_DPE_Hess(double* hess, double* grad, const double D, const double P);

IDEA_API(void) IDEA_DEP_batch(const int n, const double* D, const double* E, double* P);
IDEA_API(void) IDEA_DET_batch(const int n, const double* D, const double* E, double* T);
IDEA_API(void) IDEA_DEH_batch(const int n, const double* D, const double* E, double* H);
IDEA_API(void) IDEA_DES_batch(const int n, const double* D, const double* E, double* S);
IDEA_API(void) IDEA_DEA_batch(const int n, const double* D, const double* E, double* A);
IDEA_API(void) IDEA_DEC_batch(const int n, const double* D, const double* E, double* C);
IDEA_API(void) IDEA_DEG_batch(const int n, const double* D, const double* E, double* G);
IDEA_API(void) IDEA_DEV_batch(const int n, const double* D, const double* E, double* V);
IDEA_API(void) IDEA_DEK_batch(const int n, const double* D, const double* E, double* K);

IDEA_API(void) IDEA_PTD_batch(const int n, const double* P, const double* T, double* D);
IDEA_API(void) IDEA_PTE_batch(const int n, const double* P, const double* T, double* E);
IDEA_API(void) IDEA_PTH_batch(const int n, const double* P, const double* T, double* H);
IDEA_API(void) IDEA_PTS_batch(const int n, const double* P, const double* T, double* S);
IDEA_API(void) IDEA_PTA_batch(const int n, const double* P, const double* T, double* A);
IDEA_API(void) IDEA_PTC_batch(const int n, const double* P, const double* T, double* C);
IDEA_API(void) IDEA_PTG_batch(const int n, const double* P, const double* T, double* G);
IDEA_API(void) IDEA_PTV_batch(const int n, const double* P, const double* T, double* V);
IDEA_API(void) IDEA_PTK_batch(const int n, const double* P, const double* T, double* K);

IDEA_API(void) IDEA_DPT_batch(const int n, const double* D, const double* P, double* T);
IDEA_API(void) IDEA_DPE_batch(const int n, const double* D, const double* P, double* E);

#ifdef __cplusplus
}
#endif