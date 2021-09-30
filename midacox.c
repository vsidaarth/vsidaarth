/* CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC
   CCCCCCCCCCCCCCCCCC   MIDACO 6.0   MEX FILE   CCCCCCCCCCCCCCCCCCCCCCCCCC
   CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC 

   This is the MIDACO-MEX file 'midacox.c' for using MIDACO in Matlab.
   
   Include this file in the 'Current Directory' of Matlab and type:
   
   'mex midacox.c'   in the command window and press ENTER/RETURN. 
   
   The 'mex midacox.c' command will generate some library file 
   (e.g. midacox.dll, midacox.mexw32 or midacox.mexglx), that  
   is called by the Matlab file 'midaco.m'.
   
   If you experience any problem with generating the MEX file or can 
   not run MIDACO, please visit the MIDACO-Troubleshooting website:
   
   http://www.midaco-solver.com/index.php/more/troubleshooting

   or contact:   info@midaco-solver.com

   CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC 
   CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC 
   CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC */

#include "mex.h"
#include <time.h>
#include <math.h>
#ifndef F2C_INCLUDE
#define F2C_INCLUDE
typedef long int integer;
typedef char *address;
typedef short int shortint;
typedef float real;
typedef double doublereal;
typedef struct { real r, i; } complex;
typedef struct { doublereal r, i; } doublecomplex;
typedef long int logical;
typedef short int shortlogical;
typedef char logical1;
typedef char integer1;
#define TRUE_ (1)
#define FALSE_ (0)
#ifndef Extern
#define Extern extern
#endif
#ifdef f2c_i2
typedef short flag;
typedef short ftnlen;
typedef short ftnint;
#else
typedef long flag;
typedef long ftnlen;
typedef long ftnint;
#endif
typedef struct
{ flag cierr;
 ftnint ciunit;
 flag ciend;
 char *cifmt;
 ftnint cirec;
} cilist;
typedef struct
{ flag icierr;
 char *iciunit;
 flag iciend;
 char *icifmt;
 ftnint icirlen;
 ftnint icirnum;
} icilist;
typedef struct
{ flag oerr;
 ftnint ounit;
 char *ofnm;
 ftnlen ofnmlen;
 char *osta;
 char *oacc;
 char *ofm;
 ftnint orl;
 char *oblnk;
} olist;
typedef struct
{ flag cerr;
 ftnint cunit;
 char *csta;
} cllist;
typedef struct
{ flag aerr;
 ftnint aunit;
} alist;
typedef struct
{ flag inerr;
 ftnint inunit;
 char *infile;
 ftnlen infilen;
 ftnint *inex; 
 ftnint *inopen;
 ftnint *innum;
 ftnint *innamed;
 char *inname;
 ftnlen innamlen;
 char *inacc;
 ftnlen inacclen;
 char *inseq;
 ftnlen inseqlen;
 char  *indir;
 ftnlen indirlen;
 char *infmt;
 ftnlen infmtlen;
 char *inform;
 ftnint informlen;
 char *inunf;
 ftnlen inunflen;
 ftnint *inrecl;
 ftnint *innrec;
 char *inblank;
 ftnlen inblanklen;
} inlist;
#define VOID void
union Multitype { 
 shortint h;
 integer i;
 real r;
 doublereal d;
 complex c;
 doublecomplex z;
 };
typedef union Multitype Multitype;
typedef long Long; 
struct Vardesc { 
 char *name;
 char *addr;
 ftnlen *dims;
 int  type;
 };
typedef struct Vardesc Vardesc;
struct Namelist {
 char *name;
 Vardesc **vars;
 int nvars;
 };
typedef struct Namelist Namelist;
#define abs(x) ((x) >= 0 ? (x) : -(x))
#define dabs(x) (doublereal)abs(x)
#define min(a,b) ((a) <= (b) ? (a) : (b))
#define max(a,b) ((a) >= (b) ? (a) : (b))
#define dmin(a,b) (doublereal)min(a,b)
#define dmax(a,b) (doublereal)max(a,b)
#define F2C_proc_par_types 1
#ifdef __cplusplus
typedef int /* Unknown procedure type */ (*U_fp)(...);
typedef shortint (*J_fp)(...);
typedef integer (*I_fp)(...);
typedef real (*R_fp)(...);
typedef doublereal (*D_fp)(...), (*E_fp)(...);
typedef /* Complex */ VOID (*C_fp)(...);
typedef /* Double Complex */ VOID (*Z_fp)(...);
typedef logical (*L_fp)(...);
typedef shortlogical (*K_fp)(...);
typedef /* Character */ VOID (*H_fp)(...);
typedef /* Subroutine */ int (*S_fp)(...);
#else
typedef int /* Unknown procedure type */ (*U_fp)();
typedef shortint (*J_fp)();
typedef integer (*I_fp)();
typedef real (*R_fp)();
typedef doublereal (*D_fp)(), (*E_fp)();
typedef /* Complex */ VOID (*C_fp)();
typedef /* Double Complex */ VOID (*Z_fp)();
typedef logical (*L_fp)();
typedef shortlogical (*K_fp)();
typedef /* Character */ VOID (*H_fp)();
typedef /* Subroutine */ int (*S_fp)();
#endif
/* E_fp is for real functions when -R is not specified */
typedef VOID C_f; /* complex function */
typedef VOID H_f; /* character function */
typedef VOID Z_f; /* double complex function */
typedef doublereal E_f;
#ifndef Skip_f2c_Undefs
#undef cray
#undef gcos
#undef mc68010
#undef mc68020
#undef mips
#undef pdp11
#undef sgi
#undef sparc
#undef sun
#undef sun2
#undef sun3
#undef sun4
#undef u370
#undef u3b
#undef u3b2
#undef u3b5
#undef unix
#undef vax
#endif
#endif
#ifdef _WIN32
#define huge huged
#define near neard
#endif

static long int P;
static long int o;
static long int n;
static long int ni;
static long int m;
static long int me;
static double   maxtime;
static long int maxeval;
static long int printeval;
static double param[13];
static double *xl  = NULL;
static double *xu  = NULL;
static char  *key  = NULL;
static long int lengthPF;

static long int eval;
static long double tnow,tstart;
static long int istop;
static long int iflag;
static long int i,j;
static long int pc,tic;
static double *px = NULL;
static double pf;
static double *pg = NULL;
static double pr;
static double *pp = NULL;
static double *rw;
static long int lrw;
static long int *iw,liw;
static double *paretof;
static long int extraoffset;
static long int q,kx,kf,kg,kres,wx,wf,wg,wres,on,kbest,wbest;
static double acc,bestf[1],bestr[1],dummy_f,dummy_vio;
double gettime(){ time_t second; second = time(NULL); return (double) second; }
int midaco(long int*,long int*,long int*,long int*,long int*,long int*,double*,
            double*,double*,double*,double*,long int*,long int*,double*,
            double*,long int*,long int*,long int*,double*,long int*,char*);
void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{ 









    
  double *IN_P,*IN_o,*IN_n,*IN_ni,*IN_m,*IN_me,*IN_maxeval,*IN_maxtime,*IN_printeval,*IN_param;
  double *IN_xl,*IN_xu,*IN_istop,*IN_iflag,*IN_x,*IN_f,*IN_g;
  char   *IN_key; 
  double *OUT_xxx,*OUT_fff,*OUT_ggg,*OUT_istop,*OUT_iflag,*OUT_eval,*OUT_time,*OUT_pc;
  double *OUT_px,*OUT_pf,*OUT_pg,*OUT_pr,*OUT_pp,*OUT_acc,*OUT_PF;



  IN_istop  = (double*)mxGetPr(prhs[ 13]); istop = (long int) IN_istop[0];
  IN_iflag  = (double*)mxGetPr(prhs[ 14]); iflag = (long int) IN_iflag[0];  

  // mexPrintf("======enter");

  if((iflag == 0)&&(istop == 0))
  {
    IN_P         = (double*)mxGetPr(prhs[ 0]); 
    IN_o         = (double*)mxGetPr(prhs[ 1]);
    IN_n         = (double*)mxGetPr(prhs[ 2]);     
    IN_ni        = (double*)mxGetPr(prhs[ 3]); 
    IN_m         = (double*)mxGetPr(prhs[ 4]); 
    IN_me        = (double*)mxGetPr(prhs[ 5]);
    IN_maxeval   = (double*)mxGetPr(prhs[ 6]); 
    IN_maxtime   = (double*)mxGetPr(prhs[ 7]); 
    IN_printeval = (double*)mxGetPr(prhs[ 8]);
    IN_param     = (double*)mxGetPr(prhs[ 9]); 
    IN_xl        = (double*)mxGetPr(prhs[10]); 
    IN_xu        = (double*)mxGetPr(prhs[11]); 
    
    P         = (long int) IN_P[0];
    o         = (long int) IN_o[0];
    n         = (long int) IN_n[0];
    ni        = (long int) IN_ni[0];
    m         = (long int) IN_m[0];
    me        = (long int) IN_me[0];
    maxeval   = (long int) IN_maxeval[0];
    maxtime   =            IN_maxtime[0]; /* maxtime is DOUBLE within MEX */
    printeval = (long int) IN_printeval[0];   
    for(i=0; i<13; i++) param[i] =  IN_param[i];        
    xl = (double*)mxMalloc(sizeof(double)*n);
    xu = (double*)mxMalloc(sizeof(double)*n);
    mexMakeMemoryPersistent(xl);
    mexMakeMemoryPersistent(xu);
    for(i=0; i<n; i++)    xl[i] =  IN_xl[i];
    for(i=0; i<n; i++)    xu[i] = IN_xu[i];
    /* input of type character */
    key = (char*)mxMalloc(sizeof(char)*60);
    mexMakeMemoryPersistent(key);
    IN_key = mxArrayToString(prhs[12]); /* KEY */
    for (i= 0;i< 60 ;i++){ key[i]  =  (char) IN_key[i];}    
     px = (double*)mxMalloc(sizeof(double)*n);
     mexMakeMemoryPersistent(px);
     pg = (double*)mxMalloc(sizeof(double)*(m+2*o));
     mexMakeMemoryPersistent(pg);     
     pp = (double*)mxMalloc(sizeof(double)*(n));
     mexMakeMemoryPersistent(pp);    
    iflag = 0;
    istop = 0;
    eval  = 0;
    tnow  = 0.0;
    tstart = gettime();
    lrw = 120*n+20*m+20*o+20*P+P*(m+2*o)+o*o+5000;    
    liw = 3*n+P+2000; 

    if( o == 1 )
    {
      lengthPF = 1;
    }
    else
    {
      lengthPF = 1000 * (o+m+n) + 1 + 2000;
      if( abs((long int)param[9]) >= 1 ){ lengthPF = abs((long int)param[9]) * (o+m+n) + 1; }
    }

    rw = (  double*)mxMalloc(sizeof(  double)*lrw);
    iw = (long int*)mxMalloc(sizeof(long int)*liw);
    paretof = (  double*)mxMalloc(sizeof(  double)*lengthPF);    
    mexMakeMemoryPersistent(rw); 
    mexMakeMemoryPersistent(iw);
    mexMakeMemoryPersistent(paretof);    
    for (i=0; i<lrw; i++) rw[i] = 0.0; 
    for (i=0; i<liw; i++) iw[i] = 0; 
    for (i=0; i<lengthPF; i++) paretof[i] = 0.0;  

  extraoffset = 5*(P+o+n+m)+100;
  q    = 102*n+(m+2*o)+516 + extraoffset;   
  kx   = 9;
  kf   = 9+n;
  kg   = 9+n+1;
  kres = 9+n+1+m;  
  if( o > 1 ){ kres = 9+n+1+ (m+2*o); }
  wx   = q;
  wf   = q+n;
  wg   = q+n+1;
  wres = q+n+1+m; 
  if( o > 1 ){ wres = q+n+1+ (m+2*o); }   

    if(param[0] <= 0.0)
    {
      acc = 0.001;
    }else{
      acc = param[0];
    }       
    /* Initialize */
    bestf[0] = 1.0e+99;
    bestr[0] = 1.0e+99; 
    /* Initialize */
    dummy_f = 1.0e+99;
    dummy_vio = 1.0e+99;        
    /* Initialize print ticker */
    tic = 0;
  }
  plhs[ 0] = mxCreateDoubleMatrix(1,     P*n  ,0); /* x */ 
  plhs[ 1] = mxCreateDoubleMatrix(1,     P*o  ,0); /* f */ 
  plhs[ 2] = mxCreateDoubleMatrix(1,     P*m  ,0); /* g */     
  plhs[ 3] = mxCreateDoubleMatrix(1,       1  ,0);
  plhs[ 4] = mxCreateDoubleMatrix(1,       1  ,0);
  plhs[ 5] = mxCreateDoubleMatrix(1,       1  ,0);
  plhs[ 6] = mxCreateDoubleMatrix(1,       1  ,0);
  plhs[ 7] = mxCreateDoubleMatrix(1,       1  ,0); /* pc */
  plhs[ 8] = mxCreateDoubleMatrix(1,       n  ,0); /* px */
  plhs[ 9] = mxCreateDoubleMatrix(1,       1  ,0); /* pf */
  plhs[10] = mxCreateDoubleMatrix(1,   m+2*o  ,0); /* pg */
  plhs[11] = mxCreateDoubleMatrix(1,       1  ,0); /* pr */
  plhs[12] = mxCreateDoubleMatrix(1,       n  ,0); /* pp */   
  plhs[13] = mxCreateDoubleMatrix(1,       1  ,0); /* acc */ 
  plhs[14] = mxCreateDoubleMatrix(1, lengthPF ,0); /* PF */          
  OUT_xxx    = mxGetPr(plhs[ 0]);
  OUT_fff    = mxGetPr(plhs[ 1]);
  OUT_ggg    = mxGetPr(plhs[ 2]);    
  OUT_istop  = mxGetPr(plhs[ 3]);  
  OUT_iflag  = mxGetPr(plhs[ 4]);
  OUT_eval   = mxGetPr(plhs[ 5]);  
  OUT_time   = mxGetPr(plhs[ 6]);  
  OUT_pc     = mxGetPr(plhs[ 7]);
  OUT_PF     = mxGetPr(plhs[14]);   
  IN_x      = (double*)mxGetPr(prhs[ 15]); 
               for( i=0; i<P*n; i++){      OUT_xxx[i] = IN_x[i]; } /* x */
  IN_f      = (double*)mxGetPr(prhs[ 16]); 
               for( i=0; i<P*o; i++){      OUT_fff[i] = IN_f[i]; } /* f */
  IN_g     = (double*)mxGetPr(prhs[ 17]); 
               for( i=0; i<P*m; i++){      OUT_ggg[i] = IN_g[i]; } /* g */


  eval = eval + P;           if( eval >= maxeval ){ if(maxeval<99999999){istop = 1;} }
  tnow = gettime() - tstart; if( tnow >= maxtime ){ istop = 1; } 

// mexPrintf("======in");

  midaco(&P,&o,&n,&ni,&m,&me,&*OUT_xxx,&*OUT_fff,&*OUT_ggg,&*xl,&*xu,&iflag,
         &istop,&*param,&*rw,&lrw,&*iw,&liw,&*paretof,&lengthPF,&*key);  

// mexPrintf("======out");

    pc = 0; 
    tic = tic + P;
    if((tic >= printeval)||(eval == P)||(iflag >= 1))
    {
           pc  = 1; /* Activate printing command PC */    

                         
           if(eval > P){ tic = 0; } 
           if(rw[kres] == rw[wres]){
             kbest = kf;
             wbest = wf;
           }else{
             kbest = kres;
             wbest = wres;
           }       
              
           if((rw[wbest] < rw[kbest]) ||
              (iflag >= 1)||(iflag == -300)||(iflag == -500)){
              
                 pf = rw[wf];
                 pr = rw[wres];


                 for(i=0;i<m+2*o;i++){  pg[i] = rw[wg+i]; }
                 for(i=0;i<n;i++){  px[i] = rw[wx+i]; }  
           }
           else
           {          
                 pf = rw[kf];
                 pr = rw[kres];


                 for(i=0;i<m+2*o;i++){  pg[i] = rw[kg+i]; }
                 for(i=0;i<n;i++){  px[i] = rw[kx+i]; }                          
           }    
    
               if( (pr  < dummy_vio)||
                  ((pr == dummy_vio)&&(pf < dummy_f)) )
                  {
                    dummy_f   = pf;
                    dummy_vio = pr; 
                    pc        = 2; 
                  }    
                  if( iflag >= 100 )
                  {
                    for(i=0;i<n;i++){  px[i] = OUT_xxx[i]; }                  
                  }    

      for(i=0;i<n;i++)
      {
        pp[i] = -1; on = 1; 
        if((on==1)&&( px[i] > xu[i]+1.0e-6 )){ pp[i] = 91; on = 0; }
        if((on==1)&&( px[i] < xl[i]-1.0e-6 )){ pp[i] = 92; on = 0; }        
        if((on==1)&&( xl[i] > xu[i]       )){ pp[i] = 93; on = 0; }         
        if((on==1)&&( xl[i] == xu[i]      )){ pp[i] = 90; on = 0; }
        if((on==1)&&( fabs(px[i]-xl[i]) < (xu[i]-xl[i])/1000.0 )){ pp[i] =  0; on = 0; }                
        if((on==1)&&( fabs(xu[i]-px[i]) < (xu[i]-xl[i])/1000.0 )){ pp[i] = 22; on = 0; }     
        for( j=1; j<=21; j++)
        {
          if((on==1)&&( px[i] <= xl[i] + ((double) j) * (xu[i]-xl[i])/21.0 )){ pp[i] = j; on = 0; }        
        } 
      } 

    OUT_px     = mxGetPr(plhs[ 8]);
    OUT_pf     = mxGetPr(plhs[ 9]);
    OUT_pg     = mxGetPr(plhs[10]);
    OUT_pr     = mxGetPr(plhs[11]);
    OUT_pp     = mxGetPr(plhs[12]);   
    OUT_acc    = mxGetPr(plhs[13]);     
        
    for( i=0; i < n; i++)
    {
      OUT_px[i]    = px[i];
    }
    OUT_pf[0]    = pf;
    for( i=0; i < m+2*o; i++)
    {
      OUT_pg[i]    = pg[i];
    }
    OUT_pr[0]    = pr;
    for( i=0; i < n; i++)
    {
      OUT_pp[i]    = pp[i];
    }  
    OUT_acc[0]    = acc;
  }

  OUT_istop[0] = (double) istop;
  OUT_iflag[0] = (double) iflag;
  OUT_eval[0]  = (double) eval;
  OUT_time[0]  =          tnow;  
  OUT_pc[0]    = (double) pc;

  if( o > 1 )
  {
    for( i=0; i < lengthPF; i++)
    {      
      OUT_PF[i] = paretof[i]; 
    } 

    OUT_px     = mxGetPr(plhs[ 8]);
    OUT_pf     = mxGetPr(plhs[ 9]);
    OUT_pg     = mxGetPr(plhs[10]); 
    for( i=0; i < n; i++)
    {
      OUT_px[i]    = px[i];
    }
    OUT_pf[0]    = pf;
    for( i=0; i < m+2*o; i++)
    {
      OUT_pg[i]    = pg[i];

    }
  }    


// mexPrintf("======exit");
}


#ifndef F2C_INCLUDE
#define F2C_INCLUDE
typedef long int integer;
typedef char *address;
typedef short int shortint;
typedef float real;
typedef double doublereal;
typedef struct { real r, i; } complex;
typedef struct { doublereal r, i; } doublecomplex;
typedef long int logical;
typedef short int shortlogical;
typedef char logical1;
typedef char integer1;
#define TRUE_ (1)
#define FALSE_ (0)
#ifndef Extern
#define Extern extern
#endif
#ifdef f2c_i2
typedef short flag;
typedef short ftnlen;
typedef short ftnint;
#else
typedef long flag;
typedef long ftnlen;
typedef long ftnint;
#endif
typedef struct
{ flag cierr;
 ftnint ciunit;
 flag ciend;
 char *cifmt;
 ftnint cirec;
} cilist;
typedef struct
{ flag icierr;
 char *iciunit;
 flag iciend;
 char *icifmt;
 ftnint icirlen;
 ftnint icirnum;
} icilist;
typedef struct
{ flag oerr;
 ftnint ounit;
 char *ofnm;
 ftnlen ofnmlen;
 char *osta;
 char *oacc;
 char *ofm;
 ftnint orl;
 char *oblnk;
} olist;
typedef struct
{ flag cerr;
 ftnint cunit;
 char *csta;
} cllist;
typedef struct
{ flag aerr;
 ftnint aunit;
} alist;
typedef struct
{ flag inerr;
 ftnint inunit;
 char *infile;
 ftnlen infilen;
 ftnint *inex; 
 ftnint *inopen;
 ftnint *innum;
 ftnint *innamed;
 char *inname;
 ftnlen innamlen;
 char *inacc;
 ftnlen inacclen;
 char *inseq;
 ftnlen inseqlen;
 char  *indir;
 ftnlen indirlen;
 char *infmt;
 ftnlen infmtlen;
 char *inform;
 ftnint informlen;
 char *inunf;
 ftnlen inunflen;
 ftnint *inrecl;
 ftnint *innrec;
 char *inblank;
 ftnlen inblanklen;
} inlist;
#define VOID void
union Multitype { 
 shortint h;
 integer i;
 real r;
 doublereal d;
 complex c;
 doublecomplex z;
 };
typedef union Multitype Multitype;
typedef long Long; 
struct Vardesc { 
 char *name;
 char *addr;
 ftnlen *dims;
 int  type;
 };
typedef struct Vardesc Vardesc;
struct Namelist {
 char *name;
 Vardesc **vars;
 int nvars;
 };
typedef struct Namelist Namelist;
#define abs(x) ((x) >= 0 ? (x) : -(x))
#define dabs(x) (doublereal)abs(x)
#define min(a,b) ((a) <= (b) ? (a) : (b))
#define max(a,b) ((a) >= (b) ? (a) : (b))
#define dmin(a,b) (doublereal)min(a,b)
#define dmax(a,b) (doublereal)max(a,b)
#define F2C_proc_par_types 1
#ifdef __cplusplus
typedef int /* Unknown procedure type */ (*U_fp)(...);
typedef shortint (*J_fp)(...);
typedef integer (*I_fp)(...);
typedef real (*R_fp)(...);
typedef doublereal (*D_fp)(...), (*E_fp)(...);
typedef /* Complex */ VOID (*C_fp)(...);
typedef /* Double Complex */ VOID (*Z_fp)(...);
typedef logical (*L_fp)(...);
typedef shortlogical (*K_fp)(...);
typedef /* Character */ VOID (*H_fp)(...);
typedef /* Subroutine */ int (*S_fp)(...);
#else
typedef int /* Unknown procedure type */ (*U_fp)();
typedef shortint (*J_fp)();
typedef integer (*I_fp)();
typedef real (*R_fp)();
typedef doublereal (*D_fp)(), (*E_fp)();
typedef /* Complex */ VOID (*C_fp)();
typedef /* Double Complex */ VOID (*Z_fp)();
typedef logical (*L_fp)();
typedef shortlogical (*K_fp)();
typedef /* Character */ VOID (*H_fp)();
typedef /* Subroutine */ int (*S_fp)();
#endif
typedef VOID C_f; /* complex function */
typedef VOID H_f; /* character function */
typedef VOID Z_f; /* double complex function */
typedef doublereal E_f;
#ifndef Skip_f2c_Undefs
#undef cray
#undef gcos
#undef mc68010
#undef mc68020
#undef mips
#undef pdp11
#undef sgi
#undef sparc
#undef sun
#undef sun2
#undef sun3
#undef sun4
#undef u370
#undef u3b
#undef u3b2
#undef u3b5
#undef unix
#undef vax
#endif
#endif
#ifdef _WIN32
#define huge huged
#define near neard
#endif
static doublereal c_b14 = 0.;
static doublereal c_b16 = 3.;
static doublereal c_b27 = 10.;
static doublereal c_b45 = .5;
static doublereal c_b70 = 1e16;
static integer c__0 = 0;
static integer c__1 = 1;
static doublereal c_b141 = .1;



/* Subroutine */ int midaco(integer *p, integer *o, integer *n, integer *ni, 
	integer *m, integer *me, doublereal *x, doublereal *f, doublereal *g, 
	doublereal *xl, doublereal *xu, integer *iflag, integer *istop, 
	doublereal *param, doublereal *rw, integer *lrw, integer *iw, integer 
	*liw, doublereal *pf, integer *lpf, char *key)
{
    /* Initialized data */

    static integer ea = 0;
    static integer eb = 0;
    static integer edg = 0;
    static integer edf = 0;
    static integer eu = 0;
    static integer en = 0;
    static integer eie = 0;
    static integer em = 0;
    static integer efm = 0;

    extern /* Subroutine */ int precheck_(integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, doublereal *, 
	    doublereal *, integer *, integer *), midaco_kernel_driver__(
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, integer *, integer *, doublereal *, doublereal *, 
	    integer *, integer *, integer *, doublereal *, integer *, integer 
	    *, integer *, integer *, integer *, integer *, integer *, integer 
	    *, integer *, integer *, char *, ftnlen);
    static integer offset;

/* CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC */
/* CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC */
/* CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC */
/* CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC */
    /* Parameter adjustments */
    --f;
    --xu;
    --xl;
    --x;
    --g;
    --param;
    --rw;
    --iw;
    --pf;

    /* Function Body */
/* CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC */
    if (*iflag == 0) {
	precheck_(p, o, n, m, lrw, liw, lpf, &pf[1], &param[1], iflag, istop);
	offset = *p + *o + *o + *n + *m + 200;
/*        Setting up RW workspace entry pointers */
	ea = offset + *n * 107 + *m * 6 + *o * 7 + *p * 5 + 616;
	eb = offset + ea + *p;
	edg = offset + eb + *p;
	edf = offset + edg + *p * (*m + (*o << 1)) + 1;
	eu = offset + edf + *p;
	en = offset + eu + *o;
	eie = offset + en + *o;
	em = offset + eie + *p;
	efm = offset + em + *p;
    }
/* CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC */
    midaco_kernel_driver__(p, o, n, ni, m, me, &f[1], &g[1], &x[1], &xl[1], &
	    xu[1], iflag, istop, &param[1], &rw[1], lrw, &iw[1], liw, &pf[1], 
	    lpf, &ea, &eb, &edg, &edf, &eu, &en, &eie, &em, &efm, key, (
	    ftnlen)60);
/* CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC */
    return 0;
} /* midaco_ */

/* CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC */
/* Subroutine */ int i409_(integer *m, integer *i8, doublereal *g, doublereal 
	*i5, doublereal *i2, doublereal *i4, integer *i6, integer *i43)
{
    /* System generated locals */
    integer i__1, i__2, i__3;

    /* Local variables */
    static integer i__, j, k, t;
    static doublereal z__;
    static integer i10;
    extern doublereal o25_(doublereal *);
    static integer ok;
    extern integer i301_(doublereal *, doublereal *);
    static integer i450;

    /* Parameter adjustments */
    --i6;
    --i4;
    --i2;
    --i5;
    --g;

    /* Function Body */
    i__1 = *m;
    for (k = 1; k <= i__1; ++k) {
	i6[*i43 + k - 1] = k;
    }
    i__1 = *m;
    for (k = 1; k <= i__1; ++k) {
	j = (integer) ((doublereal) k * o25_(&i4[1])) + 1;
	i6[*i43 + k - 1] = i6[*i43 + j - 1];
	i6[*i43 + j - 1] = k;
    }
    i__1 = *m;
    for (t = 1; t <= i__1; ++t) {
	i__ = i6[*i43 + t - 1];
	if (i__ <= *m - *i8) {
	    goto L79;
	}
	i__2 = *m;
	for (k = *m - *i8 + 1; k <= i__2; ++k) {
	    if (i301_(&g[i__], &g[k]) == 1 && i__ != k) {
		i450 = 0;
		i10 = 0;
		while(i450 == 0) {
		    ++i10;
		    z__ = g[i__] + (doublereal) i10;
		    if (z__ > i2[i__]) {
			goto L88;
		    }
		    ok = 0;
		    i__3 = *m;
		    for (j = *m - *i8 + 1; j <= i__3; ++j) {
			if (i__ != j && i301_(&z__, &g[j]) == 0) {
			    ++ok;
			}
		    }
		    if (ok == *i8 - 1) {
			i450 = 1;
			g[i__] = z__;
			goto L123;
		    }
L88:
		    z__ = g[i__] - (doublereal) i10;
		    if (z__ < i5[i__]) {
			goto L99;
		    }
		    ok = 0;
		    i__3 = *m;
		    for (j = *m - *i8 + 1; j <= i__3; ++j) {
			if (i__ != j && i301_(&z__, &g[j]) == 0) {
			    ++ok;
			}
		    }
		    if (ok == *i8 - 1) {
			i450 = 1;
			g[i__] = z__;
			goto L123;
		    }
L99:
		    if ((doublereal) i10 > i2[i__] - i5[i__]) {
			goto L123;
		    }
		}
L123:
		;
	    }
	}
L79:
	;
    }
    return 0;
} /* i409_ */

/* Subroutine */ int i405_(doublereal *l, doublereal *x, integer *n, integer *
	i0, doublereal *i16, doublereal *i48, integer *i41, integer *i42)
{
    /* Initialized data */

    static integer k2 = 0;
    static doublereal i56 = 0.;
    static doublereal i75 = 0.;
    static doublereal k1 = 0.;
    static doublereal i17 = 0.;

    /* Builtin functions */
    integer i_dnnt(doublereal *);

    /* Local variables */
    extern integer i301_(doublereal *, doublereal *);
    extern /* Subroutine */ int i403_(doublereal *, integer *, integer *, 
	    doublereal *, doublereal *);

    /* Parameter adjustments */
    --i48;
    --x;

    /* Function Body */
    if (*i42 == 0) {
	k2 = 0;
	i403_(&x[1], n, i0, i16, &i17);
	i56 = *l;
	i75 = i17;
	k1 = .001;
	if (i48[5] - (doublereal) i_dnnt(&i48[5]) > 0.) {
	    k1 = i48[5] - (doublereal) i_dnnt(&i48[5]);
	}
	goto L9;
    }
    if (*n <= 0) {
	if (*l <= i56 - abs(i56) * k1) {
	    goto L7;
	}
    } else {
	i403_(&x[1], n, i0, i16, &i17);
	if (i75 <= *i16) {
	    if (i301_(&i17, &i75) == 1 && *l <= i56 - abs(i56) * k1) {
		goto L7;
	    }
	} else {
	    if (i17 <= i75 - i75 * k1) {
		goto L7;
	    }
	}
    }
    ++k2;
    if (k2 >= i_dnnt(&i48[5])) {
	goto L8;
    }
    goto L9;
L7:
    i56 = *l;
    i75 = i17;
    k2 = 0;
    goto L9;
L8:
    *i41 = 1;
    if (i75 <= *i16) {
	*i42 = 5;
    }
    if (i75 > *i16) {
	*i42 = 6;
    }
L9:
    return 0;
} /* i405_ */

/* Subroutine */ int i403_(doublereal *x, integer *n, integer *i0, doublereal 
	*i16, doublereal *i17)
{
    /* System generated locals */
    integer i__1;
    doublereal d__1, d__2;

    /* Local variables */
    static integer i__;

    /* Parameter adjustments */
    --x;

    /* Function Body */
    *i17 = 0.;
    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (i__ <= *i0) {
	    if ((d__1 = x[i__], abs(d__1)) > *i16) {
		*i17 += (d__2 = x[i__], abs(d__2));
	    }
	} else {
	    if (x[i__] < -(*i16)) {
		*i17 -= x[i__];
	    }
	}
    }
    return 0;
} /* i403_ */

/* Subroutine */ int o19_(integer *f, integer *o, integer *m, integer *i8, 
	integer *n, integer *i0, doublereal *g, doublereal *l, doublereal *x, 
	doublereal *i5, doublereal *i2, integer *i42, integer *i41, 
	doublereal *i48, doublereal *i4, integer *i32, integer *i6, integer *
	i99, integer *i30, integer *i52, integer *i50, integer *i100, char *
	i990, ftnlen i990_len)
{
    /* System generated locals */
    integer i__1, i__2;
    doublereal d__1;

    /* Builtin functions */
    integer i_dnnt(doublereal *);
    double d_nint(doublereal *);

    /* Local variables */
    static integer i__, k;
    extern /* Subroutine */ int o18_(integer *, char *, ftnlen);
    extern integer i301_(doublereal *, doublereal *);
    static integer i302, i303;
    extern integer i304_(doublereal *);
    static integer i436, egtraollset;

    /* Parameter adjustments */
    --l;
    --i2;
    --i5;
    --g;
    --x;
    --i48;
    --i4;
    --i6;

    /* Function Body */
    if (*i42 >= 100) {
	return 0;
    }
    *i30 = 100;
    if (*f <= 0 || (doublereal) (*f) > 1e99) {
	*i42 = 100;
	goto L701;
    }
    if (*m <= 0 || (doublereal) (*m) > 1e99) {
	*i42 = 102;
	goto L701;
    }
    if (*i8 < 0) {
	*i42 = 103;
	goto L701;
    }
    if (*i8 > *m) {
	*i42 = 104;
	goto L701;
    }
    if (*n < 0 || (doublereal) (*n) > 1e99) {
	*i42 = 105;
	goto L701;
    }
    if (*i0 < 0) {
	*i42 = 106;
	goto L701;
    }
    if (*i0 > *n) {
	*i42 = 107;
	goto L701;
    }
    i__1 = *m;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (i304_(&g[i__]) == 1) {
	    *i42 = 201;
	    goto L701;
	}
	if (i304_(&i5[i__]) == 1) {
	    *i42 = 202;
	    goto L701;
	}
	if (i304_(&i2[i__]) == 1) {
	    *i42 = 203;
	    goto L701;
	}
	if (g[i__] < i5[i__] - 1e-4) {
	    *i42 = 204;
	    goto L701;
	}
	if (g[i__] > i2[i__] + 1e-4) {
	    *i42 = 205;
	    goto L701;
	}
	if (i5[i__] > i2[i__] + 1e-4) {
	    *i42 = 206;
	    goto L701;
	}
    }
    if (i48[1] < 0. || i48[1] > 1e99) {
	*i42 = 301;
	goto L701;
    }
    if (i48[2] < 0. || i48[2] > 1e99) {
	*i42 = 302;
	goto L701;
    }
    if (i48[3] > 1e99 || i48[3] < -1e99) {
	*i42 = 303;
	goto L701;
    }
    if (i48[4] < 0. || i48[4] > 1e99) {
	*i42 = 304;
	goto L701;
    }
    if (i48[5] < 0. || i48[5] > 1e99) {
	*i42 = 305;
	goto L701;
    }
    if (i48[6] > 1e99 || (d__1 = i48[6] - (doublereal) i_dnnt(&i48[6]), abs(
	    d__1)) > 1e-6) {
	*i42 = 306;
	goto L701;
    }
    if (i48[7] < 0. || i48[7] > 1e99) {
	*i42 = 307;
	goto L701;
    }
    if (i48[8] < 0. || i48[8] > (doublereal) (*i30)) {
	*i42 = 308;
	goto L701;
    }
    if (i48[7] > 0. && i48[7] < i48[8]) {
	*i42 = 309;
	goto L701;
    }
    if (i48[7] > 0. && i301_(&i48[8], &c_b14) == 1) {
	*i42 = 310;
	goto L701;
    }
    if (i301_(&i48[7], &c_b14) == 1 && i48[8] > 0.) {
	*i42 = 311;
	goto L701;
    }
    if (i48[9] > 1e99 || i48[9] < -1e99) {
	*i42 = 312;
	goto L701;
    }
    if (abs(i48[12]) > 0.) {
	if ((d__1 = i48[12] - (doublereal) i_dnnt(&i48[12]), abs(d__1)) > 
		1e-6 && abs(i48[12]) > 1.) {
	    *i42 = 350;
	    goto L701;
	}
    }
    if (i48[13] < 0. || i48[13] > 3.) {
	*i42 = 351;
	goto L701;
    }
    if ((d__1 = i48[13] - (doublereal) i_dnnt(&i48[13]), abs(d__1)) > 1e-6) {
	*i42 = 352;
	goto L701;
    }
    for (i__ = 1; i__ <= 12; ++i__) {
	if (i304_(&i48[i__]) == 1) {
	    *i42 = 399;
	    goto L701;
	}
    }
    if (i48[5] > 0. && i48[5] < 1.) {
	*i42 = 347;
	goto L701;
    }
    if (i48[5] - d_nint(&i48[5]) < 0.) {
	*i42 = 348;
	goto L701;
    }
    if (*i41 < 0 || *i41 > 1) {
	*i42 = 401;
	goto L701;
    }
    if (i301_(&i48[13], &c_b16) == 1) {
	i__1 = *m;
	for (i__ = *m - *i8 + 1; i__ <= i__1; ++i__) {
	    i__2 = *m;
	    for (k = *m - *i8 + 1; k <= i__2; ++k) {
		if (i__ != k && (d__1 = g[i__] - g[k], abs(d__1)) <= .1f) {
		    *i42 = 402;
		    goto L701;
		}
	    }
	}
    }
    if (*o <= 1) {
	i436 = *n;
    } else {
	i436 = *n - (*o << 1);
    }
    egtraollset = (*f + *o + *m + i436) * 5 + 100;
    *i52 = (*m << 1) + (i436 + (*o << 1)) + (*m + 5) * *i30 + 16 + 
	    egtraollset;
    *i50 = *f + 31 + *m + *m;
    i302 = *n * *f + (*n << 1) + *m * 104 + *o * *o + (*o << 1) * *f + *o * 6 
	    + *f * 3 + 522 + (*f << 1);
    i303 = *m * 3 + *f + 92;
    if (*i32 < i302) {
	*i42 = 502;
	goto L701;
    }
    if (*i99 < i303) {
	*i42 = 602;
	goto L701;
    }
    i__1 = *i52 + (*m << 1) + *n + 3;
    for (i__ = 10; i__ <= i__1; ++i__) {
	i4[i__] = 0.;
    }
    i__1 = i303;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i6[i__] = 0;
    }
    i__1 = *m;
    for (i__ = *m - *i8 + 1; i__ <= i__1; ++i__) {
	if ((d__1 = g[i__] - d_nint(&g[i__]), abs(d__1)) > .001) {
	    *i42 = 881;
	    goto L701;
	}
	if ((d__1 = i5[i__] - d_nint(&i5[i__]), abs(d__1)) > .001) {
	    *i42 = 882;
	    goto L701;
	}
	if ((d__1 = i2[i__] - d_nint(&i2[i__]), abs(d__1)) > .001) {
	    *i42 = 883;
	    goto L701;
	}
    }
    o18_(&i6[*i50 + 1], i990, (ftnlen)60);
    i6[*i50 + 61] = 0;
    for (i__ = 1; i__ <= 60; ++i__) {
	i6[*i50 + 61] += i6[*i50 + i__];
    }
    if (i6[*i50 + 61] != 2051) {
	*i42 = 900;
	goto L701;
    }
    for (i__ = 4; i__ <= 7; ++i__) {
	i4[i__] = (doublereal) i6[*i50 + i__ - 3];
    }
    i4[8] = (doublereal) i6[*i50 + 61];
    *i100 = 0;
    i__1 = *m;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (g[i__] > 1e16 || g[i__] < -1e16) {
	    *i42 = 51;
	    goto L702;
	}
	if (i5[i__] > 1e16 || i5[i__] < -1e16) {
	    *i42 = 52;
	    goto L702;
	}
	if (i2[i__] > 1e16 || i2[i__] < -1e16) {
	    *i42 = 53;
	    goto L702;
	}
	if (i301_(&i5[i__], &i2[i__]) == 1) {
	    *i42 = 71;
	    goto L702;
	}
    }
    if (i304_(&l[1]) == 1) {
	*i42 = 81;
	goto L702;
    }
    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (i304_(&x[i__]) == 1) {
	    *i42 = 82;
	    goto L702;
	}
    }
    if (abs(i48[3]) > 1e16) {
	*i42 = 91;
	goto L702;
    }
    if (abs(i48[9]) > 1e16) {
	*i42 = 92;
	goto L702;
    }
    return 0;
L701:
    *i41 = 1;
    return 0;
L702:
    *i100 = 1;
    return 0;
} /* o19_ */

/* Subroutine */ int i410_(integer *o, integer *m, integer *n, doublereal *l, 
	doublereal *x, doublereal *g, doublereal *pl, doublereal *px, 
	doublereal *pg, integer *i449, integer *i452, doublereal *k6, integer 
	*i448, doublereal *i306, doublereal *i307, doublereal *g004, integer *
	g005, integer *fx13, integer *io10, doublereal *io16, integer *io2)
{
    /* Initialized data */

    static integer i453 = 0;
    static integer ii = 0;
    static integer k5 = 0;
    static doublereal i411 = 0.;

    /* System generated locals */
    integer i__1, i__2, i__3;
    doublereal d__1, d__2;

    /* Local variables */
    static integer i__, j, k;
    static doublereal y, z__, k2, k4;
    extern /* Subroutine */ int o9_(doublereal *, doublereal *, doublereal *, 
	    integer *, integer *, integer *, doublereal *);
    static integer i440, i441, i437, i438;
    static doublereal i439;
    extern doublereal i305_(void);
    static doublereal fx11;
    static integer fx03;
    static doublereal fx14;
    static integer fx05, fx06;
    static doublereal fx12, fx21[1000], fx22, fx01;
    static integer fx08[1000], fx04;
    static doublereal fx02;
    extern /* Subroutine */ int ol004_(integer *, integer *, integer *, 
	    doublereal *, doublereal *, doublereal *, integer *, integer *);
    extern doublereal rio5_(doublereal *, doublereal *);
    static doublereal k6_i438__;

    /* Parameter adjustments */
    --fx13;
    --i307;
    --i306;
    --pg;
    --px;
    --pl;
    --g;
    --x;
    --l;

    /* Function Body */
    *io2 = 0;
    if (*i449 == 0) {
	i453 = 0;
	ii = 0;
	k5 = 0;
	i411 = 0.;
	goto L888;
    }
    if (*i449 >= 2) {
	i__1 = *i449;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    fx02 = 0.;
	    i__2 = *o;
	    for (j = 1; j <= i__2; ++j) {
		z__ = pl[*o * (i__ - 1) + j];
		fx02 += (d__1 = l[j] - z__, abs(d__1));
	    }
	    if (fx02 <= 1e-6) {
		return 0;
	    }
	}
    }
    fx14 = *k6 - *k6 / (doublereal) (*g005);
    k6_i438__ = 1e-12;
    i438 = 0;
    fx04 = 0;
    i__1 = *o;
    for (j = 1; j <= i__1; ++j) {
/* Computing MAX */
	d__1 = 1e-8, d__2 = i307[j] - i306[j];
	fx21[j - 1] = max(d__1,d__2);
	fx04 += fx13[j];
    }
    i__1 = *i449;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i437 = 0;
	fx05 = 0;
	fx03 = 1;
	i__2 = *o;
	for (j = 1; j <= i__2; ++j) {
	    if (fx13[j] == 1) {
		goto L123;
	    }
	    z__ = pl[*o * (i__ - 1) + j];
	    if (l[j] <= z__) {
		if (l[j] <= z__ - fx21[j - 1] * fx14) {
		    ++i437;
		}
		if (l[j] < z__ - fx21[j - 1] * .01) {
		    fx05 = 1;
		}
	    } else {
		if (l[j] > z__ + fx21[j - 1] * .001) {
		    fx03 = 0;
		}
	    }
L123:
	    ;
	}
	if (i437 < *o - fx04 && fx03 == 1 && fx05 == 1) {
	    pl[*o * (i__ - 1) + 1] = -30111979.;
	    ++i438;
	}
	if (i437 == 0 && i438 == 0) {
	    return 0;
	}
	if (i437 == *o - fx04) {
	    pl[*o * (i__ - 1) + 1] = -30111979.;
	    ++i438;
	}
    }
    if (*i449 <= 10) {
	goto L777;
    }
    if (i438 >= 1) {
	goto L777;
    }
    fx06 = 0;
    i__1 = *o;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (l[i__] > i307[i__]) {
	    fx06 = 1;
	}
    }
    if (fx06 >= 1) {
	fx22 = 0.;
	k2 = 0.;
	i__1 = *o;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    if (l[i__] > i307[i__]) {
		k2 += (d__1 = l[i__] - i307[i__], abs(d__1)) / fx21[i__ - 1];
	    }
	    if (l[i__] < i306[i__]) {
		fx22 += (d__1 = l[i__] - i306[i__], abs(d__1)) / fx21[i__ - 1]
			;
	    }
	}
	if (k2 > fx22 * 100.) {
	    if (*o <= 2) {
		*io2 = 0;
		return 0;
	    } else {
		if (k2 > .01) {
		    *io2 = 0;
		    return 0;
		}
	    }
	}
    }
L777:
    if (i438 == 0) {
	goto L888;
    }
    i__1 = *i449 - i438;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if ((d__1 = pl[*o * (i__ - 1) + 1] + 30111979., abs(d__1)) <= 
		k6_i438__) {
	    i__2 = *i449;
	    for (j = *i449 - i438 + 1; j <= i__2; ++j) {
		if ((d__1 = pl[*o * (j - 1) + 1] + 30111979., abs(d__1)) > 
			k6_i438__) {
		    i__3 = *o;
		    for (k = 1; k <= i__3; ++k) {
			pl[*o * (i__ - 1) + k] = pl[*o * (j - 1) + k];
		    }
		    i__3 = *n;
		    for (k = 1; k <= i__3; ++k) {
			px[*n * (i__ - 1) + k] = px[*n * (j - 1) + k];
		    }
		    i__3 = *m;
		    for (k = 1; k <= i__3; ++k) {
			pg[*m * (i__ - 1) + k] = pg[*m * (j - 1) + k];
		    }
		    pl[*o * (j - 1) + 1] = -30111979.;
		    goto L1;
		}
	    }
	}
L1:
	;
    }
    *i449 -= i438;
L888:
    *io2 = 1;
    if (*i449 == *i452 && *i448 == 1) {
	goto L999;
    }
    if (*i449 == *i452) {
	k4 = i305_();
	i__1 = *i449;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    i439 = 0.;
	    i__2 = *o;
	    for (j = 1; j <= i__2; ++j) {
		z__ = pl[*o * (i__ - 1) + j];
		i439 += (d__1 = l[j] - z__, abs(d__1));
	    }
	    if (i439 < k4) {
		k4 = i439;
	    }
	}
	if (i453 == 1 && i411 > k4) {
	    goto L999;
	}
	i440 = 1;
	i441 = 1;
	if (i453 == 2 && i411 > k4) {
	    i440 = ii;
	    i441 = k5;
	}
	i411 = i305_();
	i__1 = *i449;
	for (i__ = i440; i__ <= i__1; ++i__) {
	    i__2 = *i449;
	    for (k = i441; k <= i__2; ++k) {
		if (i__ != k) {
		    i439 = 0.;
		    i__3 = *o;
		    for (j = 1; j <= i__3; ++j) {
			z__ = pl[*o * (i__ - 1) + j];
			y = pl[*o * (k - 1) + j];
			i439 += (d__1 = y - z__, abs(d__1));
		    }
		    if (i439 < k4) {
			i__3 = *o;
			for (j = 1; j <= i__3; ++j) {
			    pl[*o * (i__ - 1) + j] = l[j];
			}
			i__3 = *n;
			for (j = 1; j <= i__3; ++j) {
			    px[*n * (i__ - 1) + j] = x[j];
			}
			i__3 = *m;
			for (j = 1; j <= i__3; ++j) {
			    pg[*m * (i__ - 1) + j] = g[j];
			}
			i453 = 2;
			ii = i__ - 1;
			k5 = k - 1;
			if (ii <= 0) {
			    ii = 1;
			}
			if (k5 <= 0) {
			    k5 = 1;
			}
			goto L999;
		    }
		    if (i439 < i411) {
			i411 = i439;
		    }
		}
	    }
	}
	i453 = 1;
	goto L999;
    }
    ++(*i449);
    i__1 = *o;
    for (i__ = 1; i__ <= i__1; ++i__) {
	pl[*o * (*i449 - 1) + i__] = l[i__];
    }
    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	px[*n * (*i449 - 1) + i__] = x[i__];
    }
    i__1 = *m;
    for (i__ = 1; i__ <= i__1; ++i__) {
	pg[*m * (*i449 - 1) + i__] = g[i__];
    }
L999:
    i__1 = *o;
    for (i__ = 1; i__ <= i__1; ++i__) {
	fx12 = i306[i__];
	fx11 = i307[i__];
	i306[i__] = i305_();
	i307[i__] = -i305_();
	i__2 = *i449;
	for (k = 1; k <= i__2; ++k) {
	    z__ = pl[*o * (k - 1) + i__];
	    if (z__ < i306[i__]) {
		i306[i__] = z__;
	    }
	    if (z__ > i307[i__]) {
		i307[i__] = z__;
		fx08[i__ - 1] = k;
	    }
	}
	if (rio5_(&fx12, &i306[i__]) > 1e-16) {
	    o9_(g004, &i306[i__], &fx12, o, g005, io10, io16);
	}
	if (rio5_(&fx11, &i307[i__]) > 1e-16) {
	    o9_(g004, &i307[i__], &fx11, o, g005, io10, io16);
	}
    }
    if (*i449 < 4) {
	return 0;
    }
    i__1 = *o;
    for (j = 1; j <= i__1; ++j) {
	i__2 = *i449;
	for (k = 1; k <= i__2; ++k) {
	    k4 = 0.;
	    i__3 = *o;
	    for (i__ = 1; i__ <= i__3; ++i__) {
		if (i__ != j) {
		    k4 += (d__1 = pl[*o * (fx08[j - 1] - 1) + i__] - pl[*o * (
			    k - 1) + i__], abs(d__1)) / fx21[i__ - 1];
		}
	    }
	    if (k4 < .03) {
		fx01 = (d__1 = pl[*o * (fx08[j - 1] - 1) + j] - pl[*o * (k - 
			1) + j], abs(d__1)) / fx21[j - 1];
		if (fx01 > .03) {
		    if (fx01 / max(1e-12,k4) > 30.) {
			k4 = 0.;
			i__3 = *o;
			for (i__ = 1; i__ <= i__3; ++i__) {
			    k4 += (d__1 = pl[*o * (fx08[j - 1] - 1) + i__] - 
				    l[i__], abs(d__1));
			}
			if (k4 <= 1e-12) {
			    *io2 = 0;
			}
			ol004_(o, n, m, &pl[1], &px[1], &pg[1], i449, &fx08[j 
				- 1]);
			fx11 = i307[j];
			i307[j] = pl[*o * (k - 1) + j];
			fx08[j - 1] = k;
			o9_(g004, &i307[j], &fx11, o, g005, io10, io16);
		    }
		}
	    }
	}
    }
    return 0;
} /* i410_ */

/* Subroutine */ int ol004_(integer *o, integer *n, integer *m, doublereal *
	pl, doublereal *px, doublereal *pg, integer *i449, integer *iii)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__;

    /* Parameter adjustments */
    --pg;
    --px;
    --pl;

    /* Function Body */
    if (*iii == *i449) {
	--(*i449);
	return 0;
    }
    i__1 = *o;
    for (i__ = 1; i__ <= i__1; ++i__) {
	pl[*o * (*iii - 1) + i__] = pl[*o * (*i449 - 1) + i__];
    }
    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	px[*n * (*iii - 1) + i__] = px[*n * (*i449 - 1) + i__];
    }
    i__1 = *m;
    for (i__ = 1; i__ <= i__1; ++i__) {
	pg[*m * (*iii - 1) + i__] = pg[*m * (*i449 - 1) + i__];
    }
    --(*i449);
    return 0;
} /* ol004_ */

/* Subroutine */ int o4_(integer *i67, doublereal *g)
{
    /* Parameter adjustments */
    --g;

    /* Function Body */
    if (*i67 == 1) {
	g[1] = 26.297690237039237;
	g[2] = .187494163680378;
	g[3] = .194021736913887;
	g[4] = .024775540335352;
	g[5] = 1746.883434934608658;
	g[6] = 303.151649371507347;
	g[7] = 544.719488383699286;
	g[8] = 0.;
	g[9] = .98810327521705;
	g[10] = .5;
	g[11] = 3.4825114132e-5;
	g[12] = 0.;
	g[13] = 0.;
	g[14] = .495363052732969;
	g[15] = 25.371780665558138;
	g[16] = 5.150978141323659;
	g[17] = 0.;
	g[18] = 27.;
	g[19] = 487.;
	g[20] = 11.;
	g[21] = 121.;
	g[22] = 9.;
	g[23] = 12.;
	g[24] = 1.;
	g[25] = 3.;
	g[26] = 84.;
	g[27] = 47.;
	g[28] = 14.;
	g[29] = 505.;
	g[30] = 11.;
	g[31] = 37.;
	g[32] = 45258.;
	g[33] = 12.;
    }
    if (*i67 == 2) {
	g[1] = 1.146763245087168;
	g[2] = .026056729677485;
	g[3] = .811482535599442;
	g[4] = .940201142299118;
	g[5] = 4032.292473666903788;
	g[6] = 202.642029563531736;
	g[7] = 1313.372702421069562;
	g[8] = .601346603393201;
	g[9] = .383298858515245;
	g[10] = .099859862564629;
	g[11] = 2.57589716335e-4;
	g[12] = 0.;
	g[13] = .013130363400112;
	g[14] = .285582894290092;
	g[15] = 358.710612764431;
	g[16] = 11.18627937084192;
	g[17] = 0.;
	g[18] = 70.;
	g[19] = 3.;
	g[20] = 38.;
	g[21] = 39.;
	g[22] = 12.;
	g[23] = 7.;
	g[24] = 3.;
	g[25] = 2.;
	g[26] = 123.;
	g[27] = 1271.;
	g[28] = 25.;
	g[29] = 594.;
	g[30] = 4.;
	g[31] = 1.;
	g[32] = 9e4;
	g[33] = 14.;
    }
    if (*i67 == 3) {
	g[1] = 1.05130732527078;
	g[2] = .068168691012;
	g[3] = .94913012612605;
	g[4] = .03495305864078;
	g[5] = 1839.33201343711948;
	g[6] = 315.6969586058031;
	g[7] = 100.58161099664137;
	g[8] = .36661404415464;
	g[9] = .96831971148045;
	g[10] = .0057003413476;
	g[11] = 7.394595286e-5;
	g[12] = 0.;
	g[13] = .03438610983096;
	g[14] = .30728402309812;
	g[15] = 3.3964682257331;
	g[16] = 4.13504886409213;
	g[17] = 1.;
	g[18] = 69.13674276614443;
	g[19] = 10.21769361415745;
	g[20] = 35.15242975414574;
	g[21] = 10.37420960136661;
	g[22] = 11.70289865585099;
	g[23] = 6.13390007849438;
	g[24] = 10.86288761397882;
	g[25] = 10.49995177680284;
	g[26] = 3.07807539587381;
	g[27] = 1831.84535427625064;
	g[28] = 6.15775717990395;
	g[29] = 125.70187468277168;
	g[30] = 2.98754122037717;
	g[31] = 5.45727806379847;
	g[32] = 35596.18613576738425;
	g[33] = 5.12835328710503;
    }
    return 0;
} /* o4_ */

/* Subroutine */ int o21_(integer *m, integer *i8, doublereal *i4, integer *
	i32, integer *i49, integer *i19, integer *i6, integer *i99, integer *
	k, integer *i18, doublereal *k3, integer *i36)
{
    /* System generated locals */
    integer i__1, i__2;
    doublereal d__1, d__2;

    /* Builtin functions */
    double sqrt(doublereal), pow_dd(doublereal *, doublereal *);

    /* Local variables */
    static integer i__, j;
    static doublereal i33, i80, i76, i79, i320;

    /* Parameter adjustments */
    --i4;
    --i6;
    --k3;
    --i36;

    /* Function Body */
    i76 = sqrt((doublereal) i6[*i18]);
    i80 = k3[4] / i76;
    i79 = (1. - 1. / sqrt((doublereal) (*i8) + .1)) / k3[5];
    i__1 = *m;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i33 = i4[*i19 + i__ - 1];
	i320 = i4[*i19 + i__ - 1];
	i__2 = i6[*k];
	for (j = 2; j <= i__2; ++j) {
	    if (i4[*i19 + (j - 1) * *m + i__ - 1] > i33) {
		i33 = i4[*i19 + (j - 1) * *m + i__ - 1];
	    }
	    if (i4[*i19 + (j - 1) * *m + i__ - 1] < i320) {
		i320 = i4[*i19 + (j - 1) * *m + i__ - 1];
	    }
	}
	i4[*i49 + i__ - 1] = (i33 - i320) / i76;
	d__2 = (doublereal) i36[6];
	if (i4[*i49 + i__ - 1] < (d__1 = i4[*i19 + i__ - 1], abs(d__1)) / (
		pow_dd(&c_b27, &d__2) * (doublereal) i6[*i18])) {
	    d__2 = (doublereal) i36[6];
	    i4[*i49 + i__ - 1] = (d__1 = i4[*i19 + i__ - 1], abs(d__1)) / (
		    pow_dd(&c_b27, &d__2) * (doublereal) i6[*i18]);
	}
	if (i__ > *m - *i8) {
	    if (i4[*i49 + i__ - 1] < i80) {
		i4[*i49 + i__ - 1] = i80;
	    }
	    if (i4[*i49 + i__ - 1] < i79) {
		i4[*i49 + i__ - 1] = i79;
	    }
	}
    }
    return 0;
} /* o21_ */

/* Subroutine */ int o22_(doublereal *l, doublereal *i48, doublereal *i17, 
	doublereal *i16, integer *i42)
{
    extern integer i301_(doublereal *, doublereal *);

    /* Parameter adjustments */
    --i48;

    /* Function Body */
    if (i301_(&i48[3], &c_b14) == 1) {
	return 0;
    }
    if (*l <= i48[3]) {
	if (*i17 <= *i16) {
	    *i42 = 7;
	}
    }
    return 0;
} /* o22_ */

/* Subroutine */ int o17_(integer *p, integer *m, integer *i8, doublereal *k3,
	 integer *i36, doublereal *i48, integer *g016, integer *io26)
{
    /* Initialized data */

    static integer fx09 = 0;

    /* Builtin functions */
    integer i_dnnt(doublereal *);

    /* Local variables */
    static doublereal g[33];
    static integer i__;
    extern /* Subroutine */ int o3_(integer *, doublereal *), o4_(integer *, 
	    doublereal *), o5_(integer *, doublereal *), t5_(integer *, 
	    integer *, integer *, doublereal *);
    static integer i67;

    /* Parameter adjustments */
    --i48;
    --i36;
    --k3;

    /* Function Body */
    if (*io26 == 1) {
	fx09 = 0;
    }
    ++fx09;
    if (fx09 > 2 && *g016 == 2) {
	fx09 = 2;
	return 0;
    }
    if (fx09 > 3) {
	fx09 = 3;
	return 0;
    }
    i67 = i_dnnt(&i48[13]);
    if ((doublereal) i67 <= 0.) {
	if (*m - *i8 > 0) {
	    i67 = 1;
	}
	if (*m - *i8 == 0) {
	    i67 = 2;
	}
    }
    if (*g016 == 1) {
	o3_(&i67, g);
    }
    if (*g016 == 2) {
	o4_(&i67, g);
    }
    if (*g016 == 3) {
	o5_(&i67, g);
    }
    if (*p >= 2) {
	t5_(g016, &i67, p, g);
    }
    for (i__ = 1; i__ <= 17; ++i__) {
	k3[i__] = g[i__ - 1];
    }
    for (i__ = 1; i__ <= 16; ++i__) {
	i36[i__] = (integer) g[i__ + 16];
    }
    return 0;
} /* o17_ */

/* Subroutine */ int ol003_(doublereal *i4, doublereal *i48)
{
    /* Builtin functions */
    double sqrt(doublereal);

    /* Parameter adjustments */
    --i48;
    --i4;

    /* Function Body */
    i4[1] = .3 / (i48[2] + 1.) + .123456789;
    i4[2] = .423456789 - .3 / (sqrt(i48[2]) + 1.);
    return 0;
} /* ol003_ */

/* Subroutine */ int o23_(integer *m, integer *i8, doublereal *i4, integer *
	i32, integer *i6, integer *i99, integer *k, integer *i19, integer *
	i31, doublereal *g, doublereal *i5, doublereal *i2, doublereal *i47, 
	doublereal *k3)
{
    /* System generated locals */
    integer i__1, i__2;
    doublereal d__1;

    /* Builtin functions */
    double sqrt(doublereal), d_nint(doublereal *);

    /* Local variables */
    static integer i__, j;
    static doublereal i34, i35;
    extern /* Subroutine */ int o30_(integer *, integer *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, integer *);
    extern doublereal o25_(doublereal *), o16_(doublereal *, doublereal *);

    /* Parameter adjustments */
    --i2;
    --i5;
    --g;
    --i4;
    --i6;
    --k3;

    /* Function Body */
    i__1 = *m;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i35 = (i2[i__] - i5[i__]) / (doublereal) i6[10];
	if (i__ > *m - *i8 && i35 < k3[9]) {
	    i35 = k3[9];
	}
	if (*i47 > 0.) {
	    if (i35 > (i2[i__] - i5[i__]) / *i47) {
		i35 = (i2[i__] - i5[i__]) / *i47;
	    }
	    if (i__ > *m - *i8) {
		if (i35 < 1. / sqrt(*i47)) {
		    i35 = 1. / sqrt(*i47);
		}
	    }
	}
	i34 = o25_(&i4[1]);
	d__1 = o25_(&i4[1]);
	g[i__] = i4[*i31 + i__ - 1] + i35 * o16_(&i34, &d__1);
	if (g[i__] < i5[i__]) {
	    if (i34 >= k3[2]) {
		g[i__] = i5[i__] + (i5[i__] - g[i__]) * k3[3];
		if (g[i__] > i2[i__]) {
		    g[i__] = i2[i__];
		}
	    } else {
		g[i__] = i5[i__];
	    }
	    goto L2;
	}
	if (g[i__] > i2[i__]) {
	    if (i34 >= k3[2]) {
		g[i__] = i2[i__] - (g[i__] - i2[i__]) * k3[3];
		if (g[i__] < i5[i__]) {
		    g[i__] = i5[i__];
		}
	    } else {
		g[i__] = i2[i__];
	    }
	}
L2:
	if (i__ > *m - *i8) {
	    g[i__] = d_nint(&g[i__]);
	}
    }
    if (*i8 < *m) {
	return 0;
    }
    i__1 = *k;
    for (j = 1; j <= i__1; ++j) {
	i__2 = *m;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    if (g[i__] < i4[*i19 + (j - 1) * *m + i__ - 1]) {
		goto L88;
	    }
	    if (g[i__] > i4[*i19 + (j - 1) * *m + i__ - 1]) {
		goto L88;
	    }
	}
	o30_(m, i8, &g[1], &i5[1], &i2[1], &i4[1], i32);
	return 0;
L88:
	;
    }
    return 0;
} /* o23_ */

/* Subroutine */ int i408_(integer *i309, integer *m, integer *i8, integer *n,
	 integer *i0, doublereal *g, doublereal *l, doublereal *x, doublereal 
	*i5, doublereal *i2, integer *i42, integer *i41, doublereal *i426, 
	doublereal *i427, doublereal *i428, doublereal *i4, integer *i6, 
	doublereal *i16, doublereal *k3, integer *i36)
{
    /* Initialized data */

    static integer i43 = 0;
    static integer k6 = 0;
    static integer k10 = 0;
    static integer k11 = 0;
    static integer i59 = 0;
    static integer i58 = 0;
    static integer i14el = 0;
    static doublereal i56 = 0.;
    static integer k9 = 0;
    static integer i10ker = 0;
    static integer i21 = 0;
    static integer i430 = 0;
    static doublereal io23 = 0.;
    static integer i414 = 0;
    static integer i421 = 0;
    static integer i451 = 0;
    static integer i407 = 0;
    static integer i422 = 0;
    static integer f = 0;
    static integer i44 = 0;
    static integer k8 = 0;
    static doublereal i310 = 0.;
    static doublereal p = 0.;

    /* System generated locals */
    integer i__1, i__2;
    doublereal d__1;

    /* Builtin functions */
    double pow_dd(doublereal *, doublereal *);

    /* Local variables */
    static integer c__, i__, j, k;
    static doublereal i17, k17;
    extern doublereal o25_(doublereal *);
    extern /* Subroutine */ int o31_(doublereal *, doublereal *, integer *, 
	    integer *, doublereal *), k19_(doublereal *, integer *, integer *,
	     integer *, integer *, integer *, integer *, integer *, 
	    doublereal *, integer *, integer *, integer *, integer *, integer 
	    *, integer *, doublereal *, doublereal *, integer *), i402_(
	    doublereal *, doublereal *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *);
    static integer i313;
    extern doublereal i305_(void);
    static doublereal i416;
    static integer i415, i406;
    extern /* Subroutine */ int i412_(doublereal *, doublereal *, doublereal *
	    , doublereal *, doublereal *, doublereal *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, doublereal *), i417_(
	    integer *, integer *, integer *, doublereal *, integer *, integer 
	    *, integer *, doublereal *), ol002_(doublereal *, integer *, 
	    doublereal *, integer *, integer *);

    /* Parameter adjustments */
    --i36;
    --k3;
    --i6;
    --i4;
    --i426;
    --i2;
    --i5;
    --x;
    --l;
    --g;

    /* Function Body */
    ++k8;
    if (*i42 == 0) {
	if (*i309 > 1) {
	    if (*i309 > (integer) (((doublereal) (*m) + .1) / 2.)) {
		f = (integer) (((doublereal) (*m) + .1) / 2.);
	    } else {
		f = *i309;
	    }
	} else {
	    f = *i309;
	}
	if (f < 1) {
	    f = 1;
	}
	i56 = i305_();
	k9 = 0;
	i10ker = 0;
	i21 = 0;
	i430 = 0;
	i414 = 0;
	i421 = 0;
	i451 = 0;
	i407 = 0;
	i422 = 0;
	k8 = 0;
	i43 = 1;
	k10 = 11;
	k11 = *m + 11;
	k6 = *m + 10 + *m + 1;
	i59 = *m + 10 + *m + *m + 1;
	i58 = *m + 10 + *m + *m + *m + 1;
	i14el = *m + 10 + *m + *m + *m + *n + 1;
	i__1 = *m;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    i4[k6 + i__ - 1] = i426[i__];
	    if (i__ > *m - *i8) {
		i4[k6 + i__ - 1] = 1.;
		if (k3[17] >= 1.) {
		    i4[k6 + i__ - 1] = 0.;
		}
	    }
	}
	i__1 = *m;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    i6[i43 + i__ - 1] = i__;
	}
	i310 = pow_dd(&c_b27, &k3[16]);
	j = 84;
	k = 3;
	i44 = 0;
	k17 = 0.;
	for (i__ = 1; i__ <= 4; ++i__) {
	    k17 += i4[k + i__];
	}
	if (k17 > (doublereal) j || k17 < (doublereal) j) {
	    i44 = 1;
	    goto L888;
	}
    }
    if (*i42 == -1) {
	i421 = i407;
	i21 = i422;
    }
    i415 = 0;
    i406 = 0;
    i__1 = f;
    for (c__ = 1; c__ <= i__1; ++c__) {
	if (*n <= 0) {
	    p = l[c__];
	} else {
	    o31_(&i17, &x[1], n, i0, i16);
	    p = l[c__] + i17 * i310;
	}
	i412_(&p, &l[c__], &g[(c__ - 1) * *m + 1], &x[(c__ - 1) * *n + 1], &
		i56, &i4[1], &i59, &i58, &i14el, m, n, &i313, &i416);
	if (i313 == 1) {
	    i415 = 1;
	}
	if (*i42 == -1 && i421 <= *m) {
	    if (i421 <= *m) {
		k9 = i6[i43 + i421 - 1];
		if (k9 <= *m - *i8) {
		    i417_(&i21, &i313, &k9, &i4[1], &k6, &i430, &f, i427);
		}
		if (*i42 == -1 && i21 == 1) {
		    i4[k10 + k9 - 1] = p;
		}
		if (*i42 == -1 && i21 == -1) {
		    i4[k11 + k9 - 1] = p;
		}
	    }
	    if (f > 1 && c__ < f) {
		if (i21 == -1) {
		    ++i421;
		}
		i21 = -i21;
	    }
	}
	if (*i42 == -3) {
/* Computing MAX */
	    d__1 = abs(io23);
	    if ((io23 - p) / max(d__1,1.) > 1e-8) {
		io23 = p;
		i414 = 0;
	    } else {
		++i406;
	    }
	}
    }
    if (*i41 == 1) {
	goto L999;
    }
    if (i406 >= f) {
	++i414;
    }
    i451 = 1;
    i__1 = f;
    for (c__ = 1; c__ <= i__1; ++c__) {
	if (*i42 == 0 || *i42 == -9) {
	    i421 = 0;
	    i21 = -1;
	    *i42 = -1;
	    i__2 = *m;
	    for (k = 1; k <= i__2; ++k) {
		j = (integer) ((doublereal) k * o25_(&i4[1])) + 1;
		i6[i43 + k - 1] = i6[i43 + j - 1];
		i6[i43 + j - 1] = k;
	    }
	}
	if (*i42 == -1 && i21 == -1) {
	    ++i421;
	}
	if (*i42 == -9) {
	    goto L222;
	}
	if (i421 > *m && c__ == 1) {
	    i421 = 0;
	    goto L333;
	}
	if (*i42 == -3) {
	    goto L333;
	}
L222:
	if (*i42 == 0) {
	    i21 = 1;
	}
	if (*i42 == -9) {
	    i21 = 1;
	}
	if (i421 <= *m) {
	    k9 = i6[i43 + i421 - 1];
	    i21 = -i21;
	    if (i451 == 1) {
		i407 = i421;
		i422 = i21;
		i451 = 0;
	    }
	    i402_(&g[(c__ - 1) * *m + 1], &i4[1], &i21, &k9, &k6, m, &i59, &
		    i313, &i421, &f);
	} else {
	    ol002_(&g[(c__ - 1) * *m + 1], m, &i4[1], &k6, &i59);
	}
    }
    goto L666;
L333:
    ++i10ker;
    if (i10ker == 1) {
	io23 = p;
	i414 = 0;
    }
    i__1 = f;
    for (c__ = 1; c__ <= i__1; ++c__) {
	k19_(&i4[1], &k6, i41, &i59, &i10ker, &i414, &k10, &k11, &g[(c__ - 1) 
		* *m + 1], &k9, i42, m, i8, &c__, &i415, i428, &k3[1], &i36[1]
		);
    }
L666:
    if (*i41 == 1) {
	goto L999;
    }
    i__1 = f;
    for (c__ = 1; c__ <= i__1; ++c__) {
	i__2 = *m;
	for (i__ = *m - *i8 + 1; i__ <= i__2; ++i__) {
	    g[(c__ - 1) * *m + i__] = (doublereal) ((integer) g[(c__ - 1) * *
		    m + i__]);
	}
	i__2 = *m;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    if (g[(c__ - 1) * *m + i__] < i5[i__]) {
		g[(c__ - 1) * *m + i__] = i5[i__];
	    }
	    if (g[(c__ - 1) * *m + i__] > i2[i__]) {
		g[(c__ - 1) * *m + i__] = i2[i__];
	    }
	}
    }
L888:
    if (i44 == 1) {
	goto L333;
    }
    return 0;
L999:
    l[1] = i4[i14el];
    i__1 = *m;
    for (i__ = 1; i__ <= i__1; ++i__) {
	g[i__] = i4[i59 + i__ - 1];
    }
    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	x[i__] = i4[i58 + i__ - 1];
    }
    return 0;
} /* i408_ */

/* Subroutine */ int i412_(doublereal *l, doublereal *rl, doublereal *g, 
	doublereal *x, doublereal *i56, doublereal *i4, integer *i59, integer 
	*i58, integer *i14el, integer *m, integer *n, integer *i313, 
	doublereal *i416)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__;

    /* Parameter adjustments */
    --i4;
    --x;
    --g;

    /* Function Body */
    *i313 = 0;
    if (*l < *i56) {
	*i416 = *i56;
	*i56 = *l;
	i__1 = *m;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    i4[*i59 + i__ - 1] = g[i__];
	}
	i__1 = *n;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    i4[*i58 + i__ - 1] = x[i__];
	}
	i4[*i14el] = *rl;
	*i313 = 1;
    }
    return 0;
} /* i412_ */

/* Subroutine */ int i417_(integer *i21, integer *i313, integer *k9, 
	doublereal *i4, integer *k6, integer *i430, integer *f, doublereal *
	i427)
{
    /* System generated locals */
    doublereal d__1;

    /* Builtin functions */
    double pow_dd(doublereal *, doublereal *);

    /* Local variables */
    static doublereal i44;
    extern doublereal o25_(doublereal *);

    /* Parameter adjustments */
    --i4;

    /* Function Body */
    if (*i21 == 1) {
	*i430 = 0;
    }
    if (*i313 == 1) {
	++(*i430);
    }
    if (*f > 1) {
	d__1 = (doublereal) (*f);
	i44 = pow_dd(&d__1, &c_b45);
    } else {
	i44 = 1.;
    }
    if (*i21 == -1) {
	if (*i430 == 0) {
	    i4[*k6 + *k9 - 1] /= o25_(&i4[1]) / i44 + 1.;
	    if (i4[*k6 + *k9 - 1] <= *i427) {
		i4[*k6 + *k9 - 1] = *i427;
	    }
	} else {
	    i4[*k6 + *k9 - 1] *= o25_(&i4[1]) / i44 + 1.;
	}
    }
    return 0;
} /* i417_ */

/* Subroutine */ int i402_(doublereal *g, doublereal *i4, integer *i21, 
	integer *k9, integer *k6, integer *m, integer *i59, integer *i313, 
	integer *i421, integer *f)
{
    /* Initialized data */

    static integer i404 = 0;

    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer j;

    /* Parameter adjustments */
    --i4;
    --g;

    /* Function Body */
    if (*f == 1) {
	if (*i421 == 1 && *i21 == 1) {
	    i__1 = *m;
	    for (j = 1; j <= i__1; ++j) {
		g[j] = i4[*i59 + j - 1];
	    }
	} else {
	    if (*i313 == 0) {
		if (*i21 == -1) {
		    g[*k9] = i4[*i59 + *k9 - 1];
		} else {
		    g[i404] = i4[*i59 + i404 - 1];
		    g[*k9] = i4[*i59 + *k9 - 1];
		}
	    }
	}
	if (*i21 == 1) {
	    g[*k9] += i4[*k6 + *k9 - 1];
	}
	if (*i21 == -1) {
	    g[*k9] -= i4[*k6 + *k9 - 1];
	}
    } else {
	i__1 = *m;
	for (j = 1; j <= i__1; ++j) {
	    g[j] = i4[*i59 + j - 1];
	}
	if (*i21 == 1) {
	    g[*k9] += i4[*k6 + *k9 - 1];
	}
	if (*i21 == -1) {
	    g[*k9] -= i4[*k6 + *k9 - 1];
	}
    }
    i404 = *k9;
    return 0;
} /* i402_ */

/* Subroutine */ int ol002_(doublereal *g, integer *m, doublereal *i4, 
	integer *k6, integer *i59)
{
    /* System generated locals */
    integer i__1;
    doublereal d__1, d__2;

    /* Local variables */
    static integer j;
    extern doublereal o25_(doublereal *), o16_(doublereal *, doublereal *);

    /* Parameter adjustments */
    --i4;
    --g;

    /* Function Body */
    i__1 = *m;
    for (j = 1; j <= i__1; ++j) {
	d__1 = o25_(&i4[1]);
	d__2 = o25_(&i4[1]);
	g[j] = i4[*i59 + j - 1] + i4[*k6 + j - 1] * o16_(&d__1, &d__2) / (
		doublereal) (*m);
    }
    return 0;
} /* ol002_ */

/* Subroutine */ int k19_(doublereal *i4, integer *k6, integer *i41, integer *
	i59, integer *i10ker, integer *i414, integer *k10, integer *k11, 
	doublereal *g, integer *k9, integer *i42, integer *m, integer *i8, 
	integer *c__, integer *i415, doublereal *i428, doublereal *k3, 
	integer *i36)
{
    /* Initialized data */

    static doublereal i424 = 0.;

    /* System generated locals */
    integer i__1;
    doublereal d__1, d__2, d__3;

    /* Local variables */
    static integer i__;
    extern doublereal o25_(doublereal *), o16_(doublereal *, doublereal *);
    static doublereal i444;
    extern /* Subroutine */ int io18_(doublereal *, integer *, integer *, 
	    doublereal *);

    /* Parameter adjustments */
    --i36;
    --k3;
    --g;
    --i4;

    /* Function Body */
    if (i424 > 1e6) {
	i424 = 1e6;
    }
    if (i424 < 1e-99) {
	i424 = 1e-99;
    }
    i444 = 0.;
    i__1 = *m - *i8;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (i4[*k6 + i__ - 1] > i444) {
	    i444 = i4[*k6 + i__ - 1];
	}
    }
    if (i444 <= *i428) {
	*i41 = 1;
	return 0;
    }
    if (*i10ker == 1) {
	i424 = 10.;
    } else {
	if (*c__ == 1) {
	    if (*i415 == 0) {
		i424 /= (d__1 = o25_(&i4[1]) * k3[15], abs(d__1)) + 1.;
	    }
	    if (*i415 == 1) {
		i424 *= (d__1 = o25_(&i4[1]) * k3[15], abs(d__1)) + 1.;
	    }
	}
    }
    if (*c__ == 1) {
	i__1 = *m - *i8;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    g[i__] = i4[*i59 + i__ - 1] + (i4[*k11 + i__ - 1] - i4[*k10 + i__ 
		    - 1]) * i4[*k6 + i__ - 1] * i424;
	}
	i__1 = *m;
	for (i__ = *m - *i8 + 1; i__ <= i__1; ++i__) {
	    g[i__] = i4[*i59 + i__ - 1];
	}
    } else {
	i__1 = *m - *i8;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    d__2 = o25_(&i4[1]);
	    d__3 = o25_(&i4[1]);
	    g[i__] = i4[*i59 + i__ - 1] + (i4[*k11 + i__ - 1] - i4[*k10 + i__ 
		    - 1]) * i4[*k6 + i__ - 1] * i424 * (d__1 = o16_(&d__2, &
		    d__3), abs(d__1));
	}
	i__1 = *m;
	for (i__ = *m - *i8 + 1; i__ <= i__1; ++i__) {
	    g[i__] = i4[*i59 + i__ - 1];
	}
    }
    io18_(&g[1], m, i8, &i4[1]);
    *i42 = -3;
    if (*i414 >= i36[16]) {
	*i42 = -9;
	*i10ker = 0;
	*k9 = 0;
    }
    return 0;
} /* k19_ */

/* Subroutine */ int io18_(doublereal *g, integer *m, integer *i8, doublereal 
	*i4)
{
    /* System generated locals */
    integer i__1;
    doublereal d__1;

    /* Builtin functions */
    double pow_dd(doublereal *, doublereal *), d_nint(doublereal *), sqrt(
	    doublereal);

    /* Local variables */
    static doublereal a, b;
    static integer i__;
    static doublereal z__, k6;
    extern doublereal o25_(doublereal *);
    static doublereal io19;
    extern doublereal io27_(doublereal *);
    static doublereal rio11;

    /* Parameter adjustments */
    --i4;
    --g;

    /* Function Body */
    rio11 = .99;
    a = 1.;
    b = 3.;
    if (o25_(&i4[1]) <= rio11) {
	return 0;
    }
    io19 = -a - b * o25_(&i4[1]);
    k6 = pow_dd(&c_b27, &io19);
    i__1 = *m - *i8;
    for (i__ = 1; i__ <= i__1; ++i__) {
	z__ = (d__1 = g[i__], abs(d__1));
	if (z__ - io27_(&z__) <= k6) {
	    if (g[i__] > d_nint(&g[i__])) {
		z__ = (d__1 = g[i__] - d_nint(&g[i__]), abs(d__1));
		g[i__] -= z__ / (sqrt(z__) + 1.);
	    }
	    if (g[i__] < d_nint(&g[i__])) {
		z__ = (d__1 = g[i__] - d_nint(&g[i__]), abs(d__1));
		g[i__] -= z__ / (sqrt(z__) + 1.);
	    }
	}
    }
    return 0;
} /* io18_ */

doublereal io27_(doublereal *g)
{
    /* System generated locals */
    doublereal ret_val;

    /* Builtin functions */
    double d_nint(doublereal *);

    ret_val = d_nint(g);
    if (ret_val <= *g) {
	return ret_val;
    }
    ret_val += -1.;
    return ret_val;
} /* io27_ */

/* Subroutine */ int o24_(integer *m, integer *i8, doublereal *g, doublereal *
	i5, doublereal *i2, doublereal *i4, integer *i32, integer *i6, 
	integer *i99, integer *i18, integer *k, integer *i19, doublereal *k3)
{
    /* System generated locals */
    integer i__1, i__2;
    doublereal d__1, d__2;

    /* Local variables */
    static integer i__, j;
    static doublereal i34, i35;
    extern /* Subroutine */ int o30_(integer *, integer *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, integer *);
    extern doublereal o25_(doublereal *), o16_(doublereal *, doublereal *);

    /* Parameter adjustments */
    --i2;
    --i5;
    --g;
    --i4;
    --i6;
    --k3;

    /* Function Body */
    i__1 = *m - *i8;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i34 = o25_(&i4[1]);
	if (i34 <= .25) {
	    g[i__] = i4[*i19 + i__ - 1];
	} else {
/* Computing 2nd power */
	    d__1 = (doublereal) i6[*i18];
	    i35 = (i2[i__] - i5[i__]) / (d__1 * d__1);
	    d__1 = o25_(&i4[1]);
	    d__2 = o25_(&i4[1]);
	    g[i__] = i4[*i19 + i__ - 1] + i35 * o16_(&d__1, &d__2);
	}
    }
    i__1 = *m;
    for (i__ = *m - *i8 + 1; i__ <= i__1; ++i__) {
	if (o25_(&i4[1]) <= .75) {
	    g[i__] = i4[*i19 + i__ - 1];
	} else {
	    if (o25_(&i4[1]) <= .5) {
		g[i__] = i4[*i19 + i__ - 1] + 1.;
	    } else {
		g[i__] = i4[*i19 + i__ - 1] - 1.;
	    }
	}
	if (g[i__] < i5[i__]) {
	    g[i__] = i5[i__];
	}
	if (g[i__] > i2[i__]) {
	    g[i__] = i2[i__];
	}
    }
    i34 = o25_(&i4[1]);
    i__1 = *m - *i8;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (g[i__] < i5[i__]) {
	    if (i34 >= k3[2]) {
		g[i__] = i5[i__] + (i5[i__] - g[i__]) * k3[3];
		if (g[i__] > i2[i__]) {
		    g[i__] = i2[i__];
		}
	    } else {
		g[i__] = i5[i__];
	    }
	    goto L2;
	}
	if (g[i__] > i2[i__]) {
	    if (i34 >= k3[2]) {
		g[i__] = i2[i__] - (g[i__] - i2[i__]) * k3[3];
		if (g[i__] < i5[i__]) {
		    g[i__] = i5[i__];
		}
	    } else {
		g[i__] = i2[i__];
	    }
	}
L2:
	;
    }
    if (*i8 < *m) {
	return 0;
    }
    i__1 = *k;
    for (j = 1; j <= i__1; ++j) {
	i__2 = *m;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    if (g[i__] < i4[*i19 + (j - 1) * *m + i__ - 1]) {
		goto L88;
	    }
	    if (g[i__] > i4[*i19 + (j - 1) * *m + i__ - 1]) {
		goto L88;
	    }
	}
	o30_(m, i8, &g[1], &i5[1], &i2[1], &i4[1], i32);
	return 0;
L88:
	;
    }
    return 0;
} /* o24_ */

/* Subroutine */ int o15_(integer *f, integer *o, integer *m, integer *i8, 
	integer *n, integer *i0, doublereal *g, doublereal *l, doublereal *x, 
	doublereal *i5, doublereal *i2, integer *i42, integer *i41, 
	doublereal *i48, doublereal *i4, integer *i32, integer *i6, integer *
	i99, doublereal *p, doublereal *i17, doublereal *i426, char *i990, 
	ftnlen i990_len)
{
    /* Initialized data */

    static integer i30 = 0;
    static integer i97 = 0;
    static integer i63 = 0;
    static integer i37 = 0;
    static integer i55 = 0;
    static integer i53 = 0;
    static integer i68 = 0;
    static integer i52 = 0;
    static integer i50 = 0;
    static integer i77 = 0;
    static integer i64 = 0;
    static integer i59 = 0;
    static integer i56 = 0;
    static integer i58 = 0;
    static integer i75 = 0;
    static integer i101 = 0;
    static integer fx15 = 0;
    static integer i94 = 0;
    static integer i100 = 0;
    static integer i980 = 0;
    static integer k14 = 0;
    static integer k12 = 0;
    static integer g016 = 0;
    static doublereal i60 = 0.;
    static doublereal i70 = 0.;
    static doublereal i16 = 0.;
    static doublereal i35 = 0.;
    static integer i44_coumt__ = 0;
    static integer i446 = 0;
    static integer i445 = 0;
    static integer i418 = 0;
    static integer i413 = 0;
    static integer i311 = 0;
    static doublereal i435 = 0.;
    static doublereal i420 = 0.;
    static doublereal k3[17] = { 0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0. };
    static integer i36[16] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
    static integer io26 = 0;

    /* System generated locals */
    integer i__1;
    doublereal d__1, d__2;

    /* Builtin functions */
    double sqrt(doublereal), pow_dd(doublereal *, doublereal *), d_nint(
	    doublereal *);

    /* Local variables */
    static integer c__, i__, j;
    static logical i54;
    static integer i90, i46;
    extern integer k31_(doublereal *, doublereal *, integer *);
    extern doublereal o25_(doublereal *);
    static doublereal i79;
    extern doublereal o16_(doublereal *, doublereal *);
    static doublereal k13;
    extern /* Subroutine */ int o17_(integer *, integer *, integer *, 
	    doublereal *, integer *, doublereal *, integer *, integer *), 
	    o19_(integer *, integer *, integer *, integer *, integer *, 
	    integer *, doublereal *, doublereal *, doublereal *, doublereal *,
	     doublereal *, integer *, integer *, doublereal *, doublereal *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, char *, ftnlen), k22_(integer *, integer *, integer *, 
	    integer *, doublereal *, doublereal *, doublereal *, doublereal *)
	    , o31_(doublereal *, doublereal *, integer *, integer *, 
	    doublereal *), o11_(integer *, integer *, integer *, integer *, 
	    integer *, doublereal *, doublereal *, doublereal *, doublereal *,
	     doublereal *, doublereal *, integer *, integer *, integer *, 
	    logical *, doublereal *, integer *, integer *, integer *, integer 
	    *, doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, integer *);
    extern integer i301_(doublereal *, doublereal *);
    static integer i312, i313;
    extern /* Subroutine */ int i405_(doublereal *, doublereal *, integer *, 
	    integer *, doublereal *, doublereal *, integer *, integer *);
    static doublereal i427, i428;
    extern /* Subroutine */ int i401_(doublereal *, doublereal *, doublereal *
	    , doublereal *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, doublereal *, integer 
	    *), i408_(integer *, integer *, integer *, integer *, integer *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, integer *, integer *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, integer *, doublereal *, doublereal *,
	     integer *), i409_(integer *, integer *, doublereal *, doublereal 
	    *, doublereal *, doublereal *, integer *, integer *);
    static doublereal fi17;
    extern /* Subroutine */ int ol003_(doublereal *, doublereal *);

    /* Parameter adjustments */
    --l;
    --i2;
    --i5;
    --g;
    --x;
    --i48;
    --i4;
    --i6;
    --p;
    --i17;
    --i426;

    /* Function Body */
    ++io26;
    if (io26 < 0) {
	io26 = 9999999;
    }
    if (g016 == 1) {
	if (io26 > 10000) {
	    g016 = 2;
	    o17_(f, m, i8, k3, i36, &i48[1], &g016, &io26);
	}
    }
    if (g016 == 1) {
	if (io26 > 200000) {
	    g016 = 3;
	    o17_(f, m, i8, k3, i36, &i48[1], &g016, &io26);
	}
    }
    if (*i42 >= 0) {
	i63 = 0;
	i37 = 0;
	io26 = 1;
	ol003_(&i4[1], &i48[1]);
	if (i48[1] <= 0.) {
	    i16 = .001;
	} else {
	    i16 = i48[1];
	}
	if (*i42 > 10 && *i42 < 100) {
	    *i42 = -3;
	    i100 = 0;
	    goto L79;
	}
	g016 = 1;
	o17_(f, m, i8, k3, i36, &i48[1], &g016, &io26);
	i97 = 0;
	o19_(f, o, m, i8, n, i0, &g[1], &l[1], &x[1], &i5[1], &i2[1], i42, 
		i41, &i48[1], &i4[1], i32, &i6[1], i99, &i30, &i52, &i50, &
		i100, i990, (ftnlen)60);
	if (*i42 >= 100) {
	    goto L86;
	}
	if (i100 == 1) {
	    i980 = *i42;
	    *i42 = 0;
	}
	i97 = 1;
	k22_(f, m, n, i0, &l[1], &x[1], &g[1], &i16);
	i46 = (integer) i48[2];
	fx15 = (integer) i48[4];
	i60 = 1e16;
	i70 = 1e16;
	k14 = (integer) i48[5];
	i59 = 1;
	i56 = i59 + *m;
	i58 = i56 + 1;
	i75 = i58 + *n;
	i68 = i75 + 1;
	i__1 = *m;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    i4[i52 + i59 + i__ - 1] = g[i__];
	}
	i__1 = *n;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    i4[i52 + i58 + i__ - 1] = x[i__];
	}
	i4[i52 + i56] = l[1];
	o31_(&i4[i52 + i75], &x[1], n, i0, &i16);
	i77 = 0;
	i101 = 0;
	i53 = i46;
	i55 = 0;
	if (i4[i52 + i75] > i16) {
	    if (i301_(&i48[9], &c_b14) == 1) {
		i4[i52 + i68] = i4[i52 + i56] + 1e9;
	    } else {
		i4[i52 + i68] = i48[9];
	    }
	} else {
	    i4[i52 + i68] = i4[i52 + i56];
	}
	i418 = 0;
	i413 = 0;
	i311 = 0;
	i405_(&l[1], &x[1], n, i0, &i16, &i48[1], i41, i42);
    } else {
	if (i97 != 1) {
	    *i42 = 701;
	    *i41 = 1;
	    return 0;
	}
	if (k14 > 0) {
	    i__1 = *f;
	    for (c__ = 1; c__ <= i__1; ++c__) {
		i405_(&l[c__], &x[(c__ - 1) * *n + 1], n, i0, &i16, &i48[1], 
			i41, i42);
	    }
	}
    }
L79:
    if (*i42 == -500) {
	goto L501;
    }
    if (*i42 == -300) {
	i55 = 0;
	++i53;
    }
    if (*i41 == 0) {
	i54 = FALSE_;
    } else {
	i54 = TRUE_;
	if (k12 == 1) {
	    goto L3;
	}
    }
    o11_(f, m, i8, n, i0, &g[1], &l[1], &x[1], &i5[1], &i2[1], &i16, &i63, &
	    i37, &i55, &i54, &i4[1], i32, &i6[1], i99, &i30, &i4[i52 + i68], &
	    i48[1], &p[1], &i17[1], k3, i36);
    if (i55 == -3) {
	if (io26 > 5000 && g016 == 1) {
	    g016 = 2;
	    o17_(f, m, i8, k3, i36, &i48[1], &g016, &io26);
	}
    }
    if (i55 == -3) {
	if (io26 > 100000 && g016 == 2) {
	    g016 = 3;
	    o17_(f, m, i8, k3, i36, &i48[1], &g016, &io26);
	}
    }
    if (*i42 != 5 && *i42 != 6) {
	*i42 = i55;
    }
    if (*i42 == 7) {
	goto L1;
    }
    if (*i42 == 801) {
	return 0;
    }
    if (i54) {
	if (i4[i52 + i75] > i16 && i4[*m + 11 + *n] < i4[i52 + i75]) {
	    goto L1;
	}
	if (i4[i52 + i75] <= i16 && i4[*m + 11 + *n] <= i16 && i4[*m + 10] < 
		i4[i52 + i56]) {
	    goto L1;
	}
	goto L3;
    }
    if (i55 == -3) {
	++i77;
    }
    i64 = i36[10];
    if (i311 >= 1) {
	goto L603;
    }
    if (k31_(&i4[*m + 10], &i4[*m + 11], n) == 1) {
	goto L603;
    }
L501:
    k12 = 1;
    if (i77 >= i64) {
	goto L103;
    }
    if (i55 <= -30 && i55 >= -40 && i413 == 1) {
	goto L103;
    }
    if (*i42 == -500) {
	goto L103;
    }
    goto L104;
L103:
    if (*i42 == -500) {
	goto L503;
    }
    i44_coumt__ = 0;
    *i42 = -500;
    i312 = *m + 11 + *n + 2 + *m * i30 + i30 + i30 + i30 + i30 + 1 + i30;
    i__1 = *m;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (i413 == 1) {
	    i426[i__] = sqrt(i4[i312 + i__ - 1]);
	} else {
/* Computing MAX */
	    d__1 = 1e-4, d__2 = sqrt(i4[i312 + i__ - 1]);
	    i426[i__] = max(d__1,d__2);
	}
    }
    i446 = 0;
    i445 = 0;
    l[1] = i4[*m + 10];
    i__1 = *m;
    for (i__ = 1; i__ <= i__1; ++i__) {
	g[i__] = i4[i__ + 9];
    }
    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	x[i__] = i4[*m + 11 + i__ - 1];
    }
    o31_(&fi17, &x[1], n, i0, &i16);
    i435 = l[1];
    i420 = fi17;
L503:
    ++i44_coumt__;
    if (i44_coumt__ > i36[14] * *m) {
	i445 = 1;
    }
    i427 = k3[10];
    i428 = i427;
    i__1 = *f;
    for (c__ = 1; c__ <= i__1; ++c__) {
	i401_(&l[c__], &x[(c__ - 1) * *n + 1], &g[(c__ - 1) * *m + 1], &i4[1],
		 &i56, &i58, &i59, &i75, m, n, i0, &i52, &i16, &i313);
    }
    if (*i41 >= 1) {
	goto L3;
    }
    if ((d__1 = i48[3] - 0., abs(d__1)) > 1e-12) {
	if (i4[i52 + i56] <= i48[3] && i4[i52 + i75] <= i16) {
	    *i42 = 7;
	    *i41 = 1;
	    goto L3;
	}
    }
    i408_(f, m, i8, n, i0, &g[1], &l[1], &x[1], &i5[1], &i2[1], &i446, &i445, 
	    &i426[1], &i427, &i428, &i4[1], &i6[1], &i16, k3, i36);
    if (i445 <= 0) {
	return 0;
    } else {
	o31_(&fi17, &x[1], n, i0, &i16);
	if (i420 <= i16) {
/* Computing MAX */
	    d__1 = 1., d__2 = abs(i435);
	    k13 = (i435 - l[1]) / max(d__1,d__2);
	} else {
/* Computing MAX */
	    d__1 = 1., d__2 = abs(i420);
	    k13 = (i420 - fi17) / max(d__1,d__2);
	}
	if (i413 == 1) {
	    i413 = 0;
	    *i42 = 0;
	    i55 = 0;
	    i__1 = i50;
	    for (i__ = 1; i__ <= i__1; ++i__) {
		i6[i__] = 0;
	    }
	    i__1 = i52;
	    for (i__ = 10; i__ <= i__1; ++i__) {
		i4[i__] = 0.;
	    }
	    goto L79;
	}
/* Computing MAX */
	d__1 = 1., d__2 = (doublereal) i44_coumt__ / (doublereal) (*m);
	if (k13 / sqrt((max(d__1,d__2))) <= k3[9] || k13 <= 0.) {
	    ++i418;
	    if (i418 >= i36[13]) {
		i311 = 1;
	    }
	} else {
	    i418 = 0;
	}
    }
    i4[*m + 10] = l[1];
    i__1 = *m;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i4[i__ + 9] = g[i__];
    }
    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i4[*m + 11 + i__ - 1] = x[i__];
    }
    o31_(&fi17, &x[1], n, i0, &i16);
    i4[*m + 11 + *n] = fi17;
L104:
L603:
    k12 = 0;
    if (i77 >= i64) {
	++i101;
	if (i4[i52 + i75] > i16 && i4[*m + 11 + *n] < i4[i52 + i75]) {
	    goto L11;
	}
	if (i4[i52 + i75] <= i16 && i4[*m + 11 + *n] <= i16 && i4[*m + 10] < 
		i4[i52 + i56]) {
	    goto L11;
	}
	goto L12;
L11:
	i4[i52 + i56] = i4[*m + 10];
	i4[i52 + i75] = i4[*m + 11 + *n];
	i__1 = *m;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    i4[i52 + i59 + i__ - 1] = i4[i__ + 9];
	}
	i__1 = *n;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    i4[i52 + i58 + i__ - 1] = i4[*m + 11 + i__ - 1];
	}
	if (i4[i52 + i75] <= i16) {
	    i4[i52 + i68] = i4[i52 + i56];
	}
	goto L13;
L12:
L13:
	i__1 = i52;
	for (i__ = 10; i__ <= i__1; ++i__) {
	    i4[i__] = 0.;
	}
	i__1 = i50;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    i6[i__] = 0;
	}
	if (o25_(&i4[1]) >= k3[7] || i48[6] < 0.) {
	    i__1 = *m;
	    for (i__ = 1; i__ <= i__1; ++i__) {
		if (*m <= *m - *i8) {
		    d__1 = (doublereal) i36[12];
		    i35 = (i2[i__] - i5[i__]) / (o25_(&i4[1]) * pow_dd(&c_b27,
			     &d__1));
		}
		i79 = (i2[i__] - i5[i__] - (i2[i__] - i5[i__]) / sqrt((
			doublereal) (*i8) + .1)) / (doublereal) i36[11];
		if (*m > *m - *i8) {
		    i35 = (i2[i__] - i5[i__]) * k3[12];
		}
		if (i__ > *m - *i8 && i35 < i79) {
		    i35 = i79;
		}
		d__1 = o25_(&i4[1]);
		d__2 = o25_(&i4[1]);
		g[i__] = i4[i52 + i59 + i__ - 1] + i35 * o16_(&d__1, &d__2);
		if (g[i__] < i5[i__]) {
		    g[i__] = i5[i__] + (i5[i__] - g[i__]) * k3[13];
		}
		if (g[i__] > i2[i__]) {
		    g[i__] = i2[i__] - (g[i__] - i2[i__]) * k3[13];
		}
		if (g[i__] < i5[i__]) {
		    g[i__] = i5[i__];
		}
		if (g[i__] > i2[i__]) {
		    g[i__] = i2[i__];
		}
		if (i__ > *m - *i8) {
		    g[i__] = d_nint(&g[i__]);
		}
	    }
	} else {
	    i__1 = *m;
	    for (i__ = 1; i__ <= i__1; ++i__) {
		g[i__] = i5[i__] + o25_(&i4[1]) * (i2[i__] - i5[i__]);
		if (i__ > *m - *i8) {
		    g[i__] = d_nint(&g[i__]);
		}
	    }
	}
	*i42 = -300;
	i77 = 0;
	if (fx15 > 0) {
	    if (i301_(&i60, &c_b70) == 1) {
		i94 = 0;
		i60 = i4[i52 + i56];
		i70 = i4[i52 + i75];
	    } else {
		if (i4[i52 + i75] <= i70) {
		    if (i70 <= i16) {
			if (i4[i52 + i56] < i60 - (d__1 = i60 / 1e6, abs(d__1)
				)) {
			    i60 = i4[i52 + i56];
			    i70 = i4[i52 + i75];
			    i94 = 0;
			} else {
			    ++i94;
			    goto L76;
			}
		    } else {
			i94 = 0;
			i60 = i4[i52 + i56];
			i70 = i4[i52 + i75];
		    }
		} else {
		    ++i94;
		    goto L76;
		}
	    }
L76:
	    if (i94 >= fx15) {
		if (i4[i52 + i75] <= i16) {
		    *i42 = 3;
		} else {
		    *i42 = 4;
		}
		goto L3;
	    }
	}
    }
    if (i100 == 1) {
	*i42 = i980;
    }
    if (k3[16] >= 1.) {
	i__1 = *f;
	for (c__ = 1; c__ <= i__1; ++c__) {
	    i409_(m, i8, &g[(c__ - 1) * *m + 1], &i5[1], &i2[1], &i4[1], &i6[
		    1], &i50);
	}
    }
    return 0;
L1:
    i4[i52 + i56] = i4[*m + 10];
    i4[i52 + i75] = i4[*m + 11 + *n];
    i__1 = *m;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i4[i52 + i59 + i__ - 1] = i4[i__ + 9];
    }
    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i4[i52 + i58 + i__ - 1] = i4[*m + 11 + i__ - 1];
    }
    if (i4[i52 + i75] <= i16) {
	i4[i52 + i68] = i4[i52 + i56];
    }
L3:
    l[1] = i4[i52 + i56];
    i__1 = *m;
    for (i__ = 1; i__ <= i__1; ++i__) {
	g[i__] = i4[i52 + i59 + i__ - 1];
    }
    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	x[i__] = i4[i52 + i58 + i__ - 1];
    }
    if (*i42 < 3 || *i42 > 7) {
	if (i4[i52 + i75] <= i16) {
	    *i42 = 1;
	} else {
	    *i42 = 2;
	}
    }
    *i41 = 1;
L86:
    if (*i42 == 501 || *i42 == 601) {
	goto L5;
    }
    i90 = i52 + 5 + *m + *n;
    i__1 = *m;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (g[i__] > i2[i__] + 1e-6) {
	    i4[i90 + i__] = 91.;
	    goto L87;
	}
	if (g[i__] < i5[i__] - 1e-6) {
	    i4[i90 + i__] = 92.;
	    goto L87;
	}
	if (i5[i__] > i2[i__]) {
	    i4[i90 + i__] = 93.;
	    goto L87;
	}
	if (i301_(&i5[i__], &i2[i__]) == 1) {
	    i4[i90 + i__] = 90.;
	    goto L87;
	}
	if ((d__1 = g[i__] - i5[i__], abs(d__1)) <= (i2[i__] - i5[i__]) / 1e3)
		 {
	    i4[i90 + i__] = 0.;
	    goto L87;
	}
	if ((d__1 = g[i__] - i2[i__], abs(d__1)) <= (i2[i__] - i5[i__]) / 1e3)
		 {
	    i4[i90 + i__] = 22.;
	    goto L87;
	}
	for (j = 1; j <= 21; ++j) {
	    if (g[i__] <= i5[i__] + j * (i2[i__] - i5[i__]) / 21.) {
		i4[i90 + i__] = (doublereal) j;
		goto L87;
	    }
	}
L87:
	;
    }
L5:
    return 0;
} /* o15_ */

/* Subroutine */ int i401_(doublereal *l, doublereal *x, doublereal *g, 
	doublereal *i4, integer *i56, integer *i58, integer *i59, integer *
	i75, integer *m, integer *n, integer *i0, integer *i52, doublereal *
	i16, integer *i313)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__;
    extern /* Subroutine */ int o31_(doublereal *, doublereal *, integer *, 
	    integer *, doublereal *);
    static doublereal fi17;

    /* Parameter adjustments */
    --i4;
    --g;
    --x;

    /* Function Body */
    *i313 = 0;
    o31_(&fi17, &x[1], n, i0, i16);
    if (i4[*i52 + *i75] > *i16 && fi17 < i4[*i52 + *i75]) {
	goto L15;
    }
    if (i4[*i52 + *i75] <= *i16 && fi17 <= *i16 && *l < i4[*i52 + *i56]) {
	goto L15;
    }
    goto L16;
L15:
    i4[*i52 + *i56] = *l;
    i4[*i52 + *i75] = fi17;
    i__1 = *m;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i4[*i52 + *i59 + i__ - 1] = g[i__];
    }
    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i4[*i52 + *i58 + i__ - 1] = x[i__];
    }
    *i313 = 1;
L16:
    return 0;
} /* i401_ */

integer k31_(doublereal *l, doublereal *x, integer *n)
{
    /* System generated locals */
    integer ret_val, i__1;

    /* Local variables */
    static integer i__;
    extern doublereal i305_(void);

    /* Parameter adjustments */
    --x;

    /* Function Body */
    ret_val = 0;
    if (*l >= i305_()) {
	ret_val = 1;
    }
    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (x[i__] <= -i305_()) {
	    ret_val = 1;
	}
    }
    return ret_val;
} /* k31_ */

/* Subroutine */ int o11_(integer *f, integer *m, integer *i8, integer *n, 
	integer *i0, doublereal *g, doublereal *l, doublereal *x, doublereal *
	i5, doublereal *i2, doublereal *i16, integer *i69, integer *i25, 
	integer *i42, logical *i41, doublereal *i4, integer *i32, integer *i6,
	 integer *i99, integer *i30, doublereal *i68, doublereal *i48, 
	doublereal *p, doublereal *i17, doublereal *k3, integer *i36)
{
    /* Initialized data */

    static integer i93 = 0;
    static integer i31 = 0;
    static integer i27 = 0;
    static integer i23 = 0;
    static integer i66 = 0;
    static integer i45 = 0;
    static integer i19 = 0;
    static integer i14 = 0;
    static integer i40 = 0;
    static integer i11 = 0;
    static integer i22 = 0;
    static integer i9 = 0;
    static integer w = 0;
    static integer i49 = 0;
    static integer i1 = 0;
    static integer i7 = 0;
    static integer i170 = 0;
    static integer k = 0;
    static integer i12 = 0;
    static integer i18 = 0;
    static integer i29 = 0;
    static integer i13 = 0;
    static integer i28 = 0;
    static integer i24 = 0;
    static integer i78 = 0;

    /* System generated locals */
    integer i__1, i__2;
    doublereal d__1;

    /* Local variables */
    static integer c__, i__, j, i65;
    extern integer k31_(doublereal *, doublereal *, integer *);
    extern /* Subroutine */ int o34_(integer *, integer *, integer *, integer 
	    *, integer *, integer *, integer *, integer *, integer *, integer 
	    *, integer *, integer *, integer *, integer *, integer *, integer 
	    *, integer *, integer *), o33_(integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *), o31_(
	    doublereal *, doublereal *, integer *, integer *, doublereal *), 
	    o22_(doublereal *, doublereal *, doublereal *, doublereal *, 
	    integer *), o27_(doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *), o36_(integer *, integer *, 
	    doublereal *, integer *, integer *, integer *, integer *, integer 
	    *, doublereal *, doublereal *, doublereal *, doublereal *), o13_(
	    integer *, integer *, integer *, doublereal *, integer *, integer 
	    *, integer *, integer *, integer *, integer *, integer *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, integer *)
	    , o26_(integer *, doublereal *, integer *, integer *, integer *, 
	    integer *, doublereal *, integer *, integer *, integer *, integer 
	    *, integer *, integer *, integer *, integer *, integer *, integer 
	    *, doublereal *, doublereal *, doublereal *, integer *), o37_(
	    integer *, doublereal *, integer *, integer *), o21_(integer *, 
	    integer *, doublereal *, integer *, integer *, integer *, integer 
	    *, integer *, integer *, integer *, doublereal *, integer *), 
	    o29_(integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *), o35_(integer *, integer *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, integer *, integer *, 
	    doublereal *, doublereal *), o30_(integer *, integer *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, integer *)
	    , o23_(integer *, integer *, doublereal *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *), o28_(
	    integer *, integer *, integer *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, integer *, integer *, integer *, 
	    integer *, doublereal *), o32_(integer *, integer *, integer *, 
	    doublereal *, doublereal *, doublereal *, integer *, integer *, 
	    doublereal *, integer *, integer *, integer *, integer *, integer 
	    *, doublereal *, integer *);
    extern integer i301_(doublereal *, doublereal *);
    extern /* Subroutine */ int o24_(integer *, integer *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, doublereal *);
    extern doublereal i305_(void);

    /* Parameter adjustments */
    --l;
    --i2;
    --i5;
    --g;
    --x;
    --i4;
    --i6;
    --i48;
    --p;
    --i17;
    --k3;
    --i36;

    /* Function Body */
    if (*i42 >= 0) {
	o34_(m, n, &i31, &i27, &i23, &i66, &i45, i30, &i19, &i14, &i40, &i11, 
		&w, &i49, &i9, &i1, &i7, &i170);
	o33_(&i12, &i29, &k, &i18, &i13, &i28, &i24, &i22);
L77:
	o31_(&i17[1], &x[1], n, i0, i16);
	i4[i27] = l[1];
	i4[i66] = i17[1];
	i__1 = *m;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    i4[i31 + i__ - 1] = g[i__];
	}
	i__1 = *n;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    i4[i23 + i__ - 1] = x[i__];
	}
	o22_(&l[1], &i48[1], &i17[1], i16, i42);
	if (*i42 == 5) {
	    return 0;
	}
	if ((d__1 = i4[8] * 2. - 4102., abs(d__1)) > .001) {
	    *i42 = -12;
	    o22_(&l[1], &i48[1], &i17[1], i16, i42);
	    i__1 = *m;
	    for (i__ = 1; i__ <= i__1; ++i__) {
		i4[i31 + i__ - 1] = x[i__];
	    }
	    i__1 = *n;
	    for (i__ = 1; i__ <= i__1; ++i__) {
		i4[i23 + i__ - 1] = g[i__];
	    }
	    goto L77;
	}
	goto L101;
    }
    i__1 = *f;
    for (c__ = 1; c__ <= i__1; ++c__) {
	if (*n <= 0) {
	    i17[c__] = 0.;
	    p[c__] = l[c__];
	} else {
	    o31_(&i17[c__], &x[(c__ - 1) * *n + 1], n, i0, i16);
	    o27_(&p[c__], &l[c__], &i17[c__], &i4[i45], i16);
	}
	if (*i42 > -30 || *i42 < -40) {
	    o36_(m, &i6[k], &i4[1], i32, &i19, &i14, &i40, &i11, &g[(c__ - 1) 
		    * *m + 1], &l[c__], &i17[c__], &p[c__]);
	}
	if (*i42 <= -30 && *i42 >= -40) {
	    o13_(f, &c__, m, &i4[1], i32, &i6[1], i99, &i19, &i14, &i40, &i11,
		     &g[(c__ - 1) * *m + 1], &l[c__], &i17[c__], &p[c__], &
		    i36[1]);
	}
	if (i17[c__] < i4[i66]) {
	    goto L123;
	}
	if (i301_(&i17[c__], &i4[i66]) == 1 && l[c__] < i4[i27]) {
	    goto L123;
	}
	goto L100;
L123:
	i4[i27] = l[c__];
	i4[i66] = i17[c__];
	i__2 = *m;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    i4[i31 + i__ - 1] = g[(c__ - 1) * *m + i__];
	}
	i__2 = *n;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    i4[i23 + i__ - 1] = x[(c__ - 1) * *n + i__];
	}
	o22_(&l[c__], &i48[1], &i17[c__], i16, i42);
	if (*i42 == 7) {
	    return 0;
	}
L100:
	;
    }
L101:
    if (*i41) {
	goto L999;
    }
    if (*i42 <= -90) {
	if (i4[i170] > *i16 && i4[i40] < i4[i170]) {
	    goto L81;
	}
	if (i4[i170] <= *i16 && i4[i40] <= *i16 && i4[i14] < i4[i7]) {
	    goto L81;
	}
	goto L82;
L81:
	i6[11] = 1;
	goto L83;
L82:
	i6[11] = 0;
L83:
	;
    }
    if (*i42 == -10) {
	if (i4[i11] < i4[i1] - (d__1 = i4[i1], abs(d__1)) / k3[7]) {
	    goto L84;
	}
	i6[13] = 0;
	goto L85;
L84:
	i6[13] = 1;
	i4[i1] = i4[i11];
L85:
	;
    }
/* Computing MIN */
    i__1 = *m * i36[9] + 2;
    i65 = min(i__1,i36[10]);
    if (i6[i18] >= i65) {
	*i42 = -95;
    }
    *i69 = 0;
    *i25 = 0;
L1000:
    if (i6[i18] == 1 && *i42 == -10) {
	i78 = 0;
    }
    if (*i42 == -10) {
	++i78;
    }
    if (*i41) {
	goto L3;
    }
    if (*i42 == -1) {
	goto L13;
    }
    if (*i42 == -2) {
	*i42 = -1;
	goto L13;
    }
    if (*i42 == -3) {
	if (i6[i13] >= i6[i29]) {
	    *i42 = -30;
	    goto L14;
	}
	*i42 = -1;
	goto L13;
    }
    if (*i42 == -30) {
	*i42 = -31;
	goto L14;
    }
    if (*i42 <= -31 && *i42 >= -39) {
	*i42 = *i42;
	goto L14;
    }
    if (*i42 == -40) {
	*i42 = -2;
	goto L12;
    }
    if (*i42 == -10) {
	*i42 = -30;
	goto L14;
    }
    if (*i42 <= -90) {
	*i42 = -3;
	goto L11;
    }
    if (*i42 == 0) {
	*i42 = -3;
	goto L11;
    }
L11:
    ++i6[i12];
    i6[i18] = 0;
    o26_(m, &i4[1], i32, &i27, &i66, &i45, i16, &i14, &i40, &i11, &i6[1], i99,
	     &i12, &k, &i28, &i24, &i22, i68, &i48[1], &k3[1], &i36[1]);
    o37_(&i6[k], &i4[1], i32, &w);
    i4[i9] = 0.;
    i__1 = i6[k];
    for (j = 1; j <= i__1; ++j) {
	i4[i9 + j] = i4[i9 + j - 1] + i4[w + j - 1];
    }
    i4[i7] = i4[i27];
    i4[i170] = i4[i66];
    i93 = 0;
    if (i6[i12] == 1) {
	if (*n > 0) {
	    o27_(&p[1], &l[1], &i17[1], &i4[i45], i16);
	}
	if (*n == 0) {
	    p[1] = l[1];
	}
	o36_(m, &i6[k], &i4[1], i32, &i19, &i14, &i40, &i11, &g[1], &l[1], &
		i17[1], &p[1]);
    }
L12:
    ++i6[i18];
    i6[i13] = 0;
    o21_(m, i8, &i4[1], i32, &i49, &i19, &i6[1], i99, &k, &i18, &k3[1], &i36[
	    1]);
    if (i48[7] > 0.) {
	i6[i29] = i6[i28];
    } else {
	o29_(&i6[1], i99, &i18, &i29, &i28, &i24, &i22);
    }
    if (i6[i18] == 1) {
	i4[i1] = i305_();
    }
    if (i6[i18] > 1) {
	i4[i1] = i4[i11];
    }
L13:
    i__1 = *f;
    for (c__ = 1; c__ <= i__1; ++c__) {
	++i6[i13];
	if (i6[i18] == 1) {
	    if (i6[10] <= 1) {
		if (i301_(&i48[6], &c_b14) == 0) {
		    d__1 = abs(i48[6]);
		    o35_(m, i8, &g[(c__ - 1) * *m + 1], &i5[1], &i2[1], &i4[1]
			    , i32, &i31, &d__1, &k3[1]);
		} else {
		    o30_(m, i8, &g[(c__ - 1) * *m + 1], &i5[1], &i2[1], &i4[1]
			    , i32);
		}
	    } else {
		d__1 = abs(i48[6]);
		o23_(m, i8, &i4[1], i32, &i6[1], i99, &k, &i19, &i31, &g[(c__ 
			- 1) * *m + 1], &i5[1], &i2[1], &d__1, &k3[1]);
	    }
	}
	if (i6[i18] > 1) {
	    o28_(m, i8, &i6[k], &g[(c__ - 1) * *m + 1], &i5[1], &i2[1], &i4[1]
		    , i32, &i19, &i49, &i9, &k3[1]);
	}
    }
    if (i6[i13] >= i6[i29] && *i42 != -3) {
	*i42 = -10;
    }
L3:
    return 0;
L14:
    if (i6[13] == 1 || i6[i18] == 1 || k31_(&i4[*m + 10], &i4[*m + 11], n) == 
	    1) {
	*i42 = -2;
	goto L12;
    } else {
	if (*i42 < -30 && i6[31] == 1) {
	    *i42 = -2;
	    goto L12;
	}
	if (*i42 == -39) {
	    i93 = 1;
	    *i42 = -99;
	    goto L101;
	}
	i__1 = *f;
	for (c__ = 1; c__ <= i__1; ++c__) {
	    if (*f > 1) {
		i6[31] = 0;
	    }
	    o32_(f, m, i8, &g[(c__ - 1) * *m + 1], &i5[1], &i2[1], &i19, &i49,
		     &i4[1], i32, &i6[1], i99, i42, &i93, &k3[1], &i36[1]);
	    if (*i42 == -30 && *f > 1) {
		*i42 = -31;
	    }
	    if (i93 == 1 && c__ > 1) {
		o24_(m, i8, &g[(c__ - 1) * *m + 1], &i5[1], &i2[1], &i4[1], 
			i32, &i6[1], i99, &i18, &k, &i19, &k3[1]);
		i93 = 0;
		*i42 = -39;
	    }
	}
	if (i93 == 1) {
	    goto L101;
	}
	goto L3;
    }
L999:
    l[1] = i4[i27];
    i17[1] = i4[i66];
    i__1 = *m;
    for (i__ = 1; i__ <= i__1; ++i__) {
	g[i__] = i4[i31 + i__ - 1];
    }
    i__1 = *n;
    for (j = 1; j <= i__1; ++j) {
	x[j] = i4[i23 + j - 1];
    }
    if (i17[1] <= *i16) {
	*i42 = 0;
    } else {
	*i42 = 1;
    }
    if (*i69 > 0) {
	goto L1000;
    }
    return 0;
} /* o11_ */

/* Subroutine */ int o12_(integer *p, integer *o, integer *m, integer *i8, 
	integer *n, integer *i0, doublereal *g, doublereal *l, doublereal *x, 
	doublereal *i5, doublereal *i2, integer *i42, integer *i41, 
	doublereal *i48, doublereal *i4, integer *i32, integer *i6, integer *
	i99, doublereal *pl, doublereal *a, doublereal *b, doublereal *
	i44_x__, doublereal *i44_l__, doublereal *i306, doublereal *i307, 
	doublereal *i426, doublereal *g014, doublereal *g003, char *i15, 
	ftnlen i15_len)
{
    /* Initialized data */

    static integer k16 = 0;
    static integer i448 = 0;
    static doublereal i16g = 0.;
    static doublereal k6 = 0.;
    static doublereal g004 = 0.;
    static integer g005 = 0;
    static integer fx20 = 0;
    static integer io20 = 0;
    static doublereal g008[1000] = { 0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0. };
    static doublereal g007 = 0.;
    static doublereal g006[1000] = { 0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0. };
    static doublereal io9 = 0.;
    static integer i431 = 0;
    static integer i432 = 0;
    static integer i433 = 0;
    static doublereal g001 = 0.;
    static doublereal io1 = 0.;
    static doublereal g002[1000] = { 0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0. };
    static integer fx13[1000] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
    static integer io4 = 0;
    static integer t4 = 0;
    static integer i449 = 0;

    /* System generated locals */
    integer i__1, i__2;

    /* Builtin functions */
    integer i_dnnt(doublereal *);

    /* Local variables */
    static integer c__, i__;
    extern /* Subroutine */ int o1_(integer *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, integer *), o6_(integer 
	    *, doublereal *, doublereal *);
    static doublereal i17;
    extern /* Subroutine */ int o15_(integer *, integer *, integer *, integer 
	    *, integer *, integer *, doublereal *, doublereal *, doublereal *,
	     doublereal *, doublereal *, integer *, integer *, doublereal *, 
	    doublereal *, integer *, integer *, integer *, doublereal *, 
	    doublereal *, doublereal *, char *, ftnlen);
    extern integer i301_(doublereal *, doublereal *);
    extern doublereal i305_(void);
    static integer io2;
    extern /* Subroutine */ int i403_(doublereal *, integer *, integer *, 
	    doublereal *, doublereal *), i410_(integer *, integer *, integer *
	    , doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, integer *, integer *, doublereal *, 
	    integer *, doublereal *, doublereal *, doublereal *, integer *, 
	    integer *, integer *, doublereal *, integer *);
    static integer io10;
    static doublereal io16;
    extern /* Subroutine */ int io17_(integer *, integer *, integer *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, integer *, doublereal *, doublereal *,
	     doublereal *, doublereal *, integer *, integer *, integer *, 
	    integer *, doublereal *, integer *), ol001_(integer *, integer *, 
	    integer *, doublereal *, doublereal *, integer *, integer *, 
	    doublereal *, integer *, integer *, doublereal *, doublereal *);
    static integer i44_n__;

    /* Parameter adjustments */
    --l;
    --i2;
    --i5;
    --g;
    --x;
    --i48;
    --i4;
    --i6;
    --pl;
    --a;
    --b;
    --i44_x__;
    --i44_l__;
    --i306;
    --i307;
    --i426;
    --g014;
    --g003;

    /* Function Body */
    ++fx20;
    if (fx20 < 0) {
	fx20 = 999999999;
    }
    if (*i42 == 0) {
	g004 = 0.;
	fx20 = 1;
	g005 = 0;
	io10 = 0;
	i16g = 0.;
	k6 = 0.;
	k16 = 0;
	i449 = 0;
	i448 = 0;
	io4 = 1;
	g001 = i305_();
	io1 = i305_();
	i__1 = *o;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    i306[i__] = i305_();
	    i307[i__] = -i305_();
	}
	io20 = 0;
	io9 = abs(i48[12]);
	if (i48[12] >= 0.) {
	    t4 = 0;
	} else {
	    t4 = 1;
	}
	o6_(o, g008, &io9);
	i__1 = *o;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    fx13[i__ - 1] = 0;
	}
	if (i48[10] < 0. && io9 < 1.) {
	    i__1 = *o;
	    for (i__ = 1; i__ <= i__1; ++i__) {
		if (g008[i__ - 1] <= 0.) {
		    fx13[i__ - 1] = 1;
		}
	    }
	}
	if (i301_(&i48[10], &c_b14) == 1) {
	    k16 = 1000;
	} else {
	    k16 = (i__1 = (integer) i48[10], abs(i__1));
	}
	ol001_(&c__0, o, m, &c_b14, &c_b14, &c__0, &c__0, &i4[1], &io20, fx13,
		 &g007, g006);
	i__1 = *p;
	for (c__ = 1; c__ <= i__1; ++c__) {
	    g014[c__] = 0.;
	}
	if (i48[1] <= 0.) {
	    i16g = .001;
	} else {
	    i16g = i48[1];
	}
	if (i301_(&i48[11], &c_b14) == 1) {
	    if (*o == 2) {
		k6 = .001;
	    }
	    if (*o >= 3) {
		k6 = .01;
	    }
	} else {
	    k6 = abs(i48[11]);
	}
	if (i48[11] < 0.) {
	    i448 = 1;
	}
	if (abs(i48[3]) > 0. && io9 < 1.) {
	    i48[3] = 0.;
	}
    }
    if (fx20 <= 2) {
	io20 = 1;
    }
    io10 = 0;
    i__1 = *p;
    for (c__ = 1; c__ <= i__1; ++c__) {
	if (*n > 0) {
	    i403_(&x[(c__ - 1) * *n + 1], n, i0, &i16g, &i17);
	} else {
	    i17 = 0.;
	}
	io2 = 0;
	if (i17 <= i16g) {
	    ++g005;
	    if (g005 <= 0) {
		g005 = 999999999;
	    }
	    i431 = 2;
	    i432 = k16 * *o + 2;
	    i433 = k16 * *o + 1 + k16 * *n + 1;
	    i449 = i_dnnt(&pl[1]);
	    if (*n > 0) {
		i410_(o, m, n, &l[(c__ - 1) * *o + 1], &x[(c__ - 1) * *n + 1],
			 &g[(c__ - 1) * *m + 1], &pl[i431], &pl[i432], &pl[
			i433], &i449, &k16, &k6, &i448, &i306[1], &i307[1], &
			g004, &g005, fx13, &io10, &io16, &io2);
	    } else {
		i410_(o, m, n, &l[(c__ - 1) * *o + 1], &x[1], &g[(c__ - 1) * *
			m + 1], &pl[i431], &pl[i432], &pl[i433], &i449, &k16, 
			&k6, &i448, &i306[1], &i307[1], &g004, &g005, fx13, &
			io10, &io16, &io2);
	    }
	    pl[1] = (doublereal) i449;
	}
	o1_(o, &l[(c__ - 1) * *o + 1], &i17, &i16g, &i306[1], &i307[1], &io9, 
		&g004, g008, &g014[c__], &g005);
	o1_(o, &l[(c__ - 1) * *o + 1], &i17, &i16g, &i306[1], &i307[1], &io9, 
		&g007, g006, &g003[c__], &g005);
	if (*n > 0) {
	    io17_(o, n, m, &g014[c__], &l[(c__ - 1) * *o + 1], &x[(c__ - 1) * 
		    *n + 1], &g[(c__ - 1) * *m + 1], &i17, &i16g, &g001, &io1,
		     g002, &pl[1], &k16, &i306[1], &i307[1], g008, &io9, &io4,
		     &io20, &io2, &io10, &io16, &g005);
	} else {
	    io17_(o, n, m, &g014[c__], &l[(c__ - 1) * *o + 1], &x[1], &g[(c__ 
		    - 1) * *m + 1], &i17, &i16g, &g001, &io1, g002, &pl[1], &
		    k16, &i306[1], &i307[1], g008, &io9, &io4, &io20, &io2, &
		    io10, &io16, &g005);
	}
	if (io1 <= i16g) {
	    if (i17 <= i16g && g014[c__] < g001) {
		g001 = g014[c__];
		io1 = i17;
		i__2 = *o;
		for (i__ = 1; i__ <= i__2; ++i__) {
		    g002[i__ - 1] = l[(c__ - 1) * *o + i__];
		}
	    }
	} else {
	    if (i17 < io1) {
		g001 = g014[c__];
		io1 = i17;
		i__2 = *o;
		for (i__ = 1; i__ <= i__2; ++i__) {
		    g002[i__ - 1] = l[(c__ - 1) * *o + i__];
		}
	    }
	}
    }
    i__1 = *p;
    for (c__ = 1; c__ <= i__1; ++c__) {
	i__2 = *n;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    i44_x__[(c__ - 1) * (*n + *o + *o) + i__] = x[(c__ - 1) * *n + 
		    i__];
	}
	i__2 = *o;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    i44_x__[(c__ - 1) * (*n + *o + *o) + *n + i__] = l[(c__ - 1) * *o 
		    + i__];
	}
	i__2 = *o;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    i44_x__[(c__ - 1) * (*n + *o + *o) + *n + *o + i__] = 0.;
	}
	i__2 = *o;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    if (i44_x__[(c__ - 1) * (*n + *o + *o) + *n + i__] < 0.) {
		i44_x__[(c__ - 1) * (*n + *o + *o) + *n + i__] = -i44_x__[(
			c__ - 1) * (*n + *o + *o) + *n + i__];
		i44_x__[(c__ - 1) * (*n + *o + *o) + *n + *o + i__] = 1.;
	    }
	}
    }
    i44_n__ = *n + *o + *o;
    i44_x__[*p * i44_n__ + 1] = 0.;
    i__1 = *p;
    for (c__ = 1; c__ <= i__1; ++c__) {
	ol001_(&c__1, o, m, &g014[c__], &g003[c__], &io10, &i449, &i4[1], &
		io20, fx13, &g007, g006);
	if (io20 == 1 || t4 == 1) {
	    i44_l__[c__] = g014[c__];
	} else {
	    i44_l__[c__] = g003[c__];
	}
    }
    o15_(p, o, m, i8, &i44_n__, i0, &g[1], &i44_l__[1], &i44_x__[1], &i5[1], &
	    i2[1], i42, i41, &i48[1], &i4[1], i32, &i6[1], i99, &a[1], &b[1], 
	    &i426[1], i15, (ftnlen)60);
    if (*i41 == 1) {
	i__1 = *o;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    if (i44_x__[*n + *o + i__] <= 0.f) {
		l[i__] = i44_x__[*n + i__];
	    }
	    if (i44_x__[*n + *o + i__] > 0.f) {
		l[i__] = -i44_x__[*n + i__];
	    }
	}
	i__1 = *n;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    x[i__] = i44_x__[i__];
	}
    }
    return 0;
} /* o12_ */

doublereal o16_(doublereal *a, doublereal *b)
{
    /* Initialized data */

    static doublereal u[30] = { .260390399999,.371464399999,.459043699999,
	    .534978299999,.603856999999,.668047299999,.728976299999,
	    .787597599999,.844600499999,.900516699999,.955780799999,
	    1.010767799999,1.065818099999,1.121257099999,1.177410099999,
	    1.234617499999,1.293250299999,1.353728799999,1.416546699999,
	    1.482303899999,1.551755799999,1.625888099999,1.706040699999,
	    1.794122699999,1.893018599999,2.007437799999,2.145966099999,
	    2.327251799999,2.608140199999,2.908140199999 };
    static doublereal v[30] = { .207911799999,.406736699999,.587785399999,
	    .743144899999,.866025499999,.951056599999,.994521999999,
	    .994521999999,.951056599999,.866025499999,.743144899999,
	    .587785399999,.406736699999,.207911799999,-.016538999999,
	    -.207911799999,-.406736699999,-.587785399999,-.743144899999,
	    -.866025499999,-.951056599999,-.994521999999,-.994521999999,
	    -.951056599999,-.866025499999,-.743144899999,-.587785399999,
	    -.406736699999,-.207911799999,-.107911799999 };

    /* System generated locals */
    integer i__1, i__2;
    doublereal ret_val;

    /* Local variables */
    static integer i__, j;

/* Computing MAX */
    i__1 = 1, i__2 = (integer) (*a * 31.);
    i__ = max(i__1,i__2);
/* Computing MAX */
    i__1 = 1, i__2 = (integer) (*b * 31.);
    j = max(i__1,i__2);
    ret_val = u[i__ - 1] * v[j - 1];
    return ret_val;
} /* o16_ */

/* Subroutine */ int o26_(integer *m, doublereal *i4, integer *i32, integer *
	i27, integer *i66, integer *i45, doublereal *i16, integer *i14, 
	integer *i40, integer *i11, integer *i6, integer *i99, integer *i12, 
	integer *k, integer *i28, integer *i24, integer *i22, doublereal *i68,
	 doublereal *i48, doublereal *k3, integer *i36)
{
    /* Initialized data */

    static integer i96 = 0;

    /* System generated locals */
    integer i__1;
    doublereal d__1, d__2, d__3, d__4;

    /* Builtin functions */
    double pow_dd(doublereal *, doublereal *);
    integer i_dnnt(doublereal *);

    /* Local variables */
    static integer j;
    extern doublereal o25_(doublereal *);
    static integer i74, i73, i72;

    /* Parameter adjustments */
    --i4;
    --i6;
    --i48;
    --k3;
    --i36;

    /* Function Body */
    if (i6[(0 + (0 + (*i12 << 2))) / 4] <= 1) {
	i6[10] = 0;
	i96 = 0;
    } else {
	++i96;
/* Computing MIN */
	d__3 = (doublereal) i36[3];
	d__4 = (doublereal) i96;
	d__1 = 1e9, d__2 = pow_dd(&d__3, &d__4);
	i6[10] = (integer) min(d__1,d__2);
    }
    if (i48[6] < 0. && i6[10] != 0) {
	d__1 = abs(i48[6]);
	i6[10] = i_dnnt(&d__1);
    }
    i74 = i36[2];
    i73 = i36[1];
    i72 = 2;
    d__1 = o25_(&i4[1]) * (doublereal) (*m);
    i6[*i28] = i72 * i_dnnt(&d__1);
    if (i48[7] >= 2.) {
	i6[*i28] = i_dnnt(&i48[7]);
    }
    if (i6[*i28] < i74) {
	i6[*i28] = i74;
    }
    if (i6[*i28] > i73) {
	i6[*i28] = i73;
    }
    d__1 = o25_(&i4[1]) * (doublereal) i6[*i28];
    i6[*k] = i_dnnt(&d__1);
    if (i48[8] >= 2.) {
	i6[*k] = i_dnnt(&i48[8]);
    }
    if (i6[*k] < 2) {
	i6[*k] = 2;
    }
    if (i6[*k] > 100) {
	i6[*k] = 100;
    }
    d__1 = o25_(&i4[1]) * (doublereal) i6[*i28];
    i6[*i24] = i6[*i28] + i36[4] * i_dnnt(&d__1);
    d__1 = k3[1] * (doublereal) i6[*k];
    i6[*i22] = i_dnnt(&d__1);
    i4[*i45] = *i68;
    if (i4[*i66] <= *i16 && i4[*i27] < *i68) {
	i4[*i45] = i4[*i27];
    }
    i__1 = i6[*k];
    for (j = 1; j <= i__1; ++j) {
	i4[*i40 + j - 1] = 1.0777e90;
	i4[*i14 + j - 1] = 1.0888e90;
	i4[*i11 + j - 1] = 1.0999e90;
    }
    return 0;
} /* o26_ */

/* Subroutine */ int ol001_(integer *io25, integer *o, integer *m, doublereal 
	*l, doublereal *fx18, integer *io10, integer *i449, doublereal *i4, 
	integer *io20, integer *fx13, doublereal *g007, doublereal *g006)
{
    /* Initialized data */

    static integer i10 = 0;
    static integer fx23 = 0;
    static integer fx24 = 0;
    static doublereal i56 = 0.;
    static doublereal io21 = 0.;

    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__;
    extern doublereal o25_(doublereal *), i305_(void);
    static integer io8;

    /* Parameter adjustments */
    --g006;
    --fx13;
    --i4;

    /* Function Body */
    if (*io25 == 0) {
	*io20 = 1;
	i56 = i305_();
	io21 = i305_();
	i10 = 0;
	fx23 = 0;
	fx24 = 0;
	*g007 = 1e8;
	i__1 = *o;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    g006[i__] = 1.;
	    if (fx13[i__] == 1) {
		g006[i__] = 0.;
	    }
	}
	goto L999;
    }
    if (*l < i56) {
	i56 = *l;
	fx24 = i10;
	i10 = 0;
	if (*io20 == 2) {
	    *io20 = 1;
	}
	goto L999;
    }
    if (*io10 >= 1) {
	fx24 = i10;
	i10 = 0;
	if (*io20 == 2) {
	    *io20 = 1;
	}
	goto L999;
    }
    if (*io20 == 1) {
	++i10;
    } else {
	if (*fx18 < io21) {
	    i10 = 0;
	    io21 = *fx18;
	} else {
	    ++i10;
	}
    }
    io8 = fx24 * 20 + min(*m,100) + (integer) (1e5 / (doublereal) (*i449 * *
	    i449 + 1));
    if (i10 >= io8) {
	*io20 = 2;
	io21 = i305_();
	i__1 = *o;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    g006[i__] = o25_(&i4[1]);
	    if (fx13[i__] == 1) {
		g006[i__] = 0.;
	    }
	}
    }
L999:
    ++fx23;
    return 0;
} /* ol001_ */

/* Subroutine */ int o27_(doublereal *p, doublereal *l, doublereal *i17, 
	doublereal *i45, doublereal *i16)
{
    /* System generated locals */
    doublereal d__1;

    /* Local variables */
    static doublereal i61;

    i61 = *l - *i45;
    if (*l <= *i45 && *i17 <= *i16) {
	*p = i61;
	return 0;
    } else {
	if (*l <= *i45) {
	    *p = *i17;
	    return 0;
	} else {
	    if (*i17 <= i61) {
/* Computing 2nd power */
		d__1 = *i17;
		*p = i61 + d__1 * d__1 / (i61 * 2.) - *i17 / 2.;
	    } else {
/* Computing 2nd power */
		d__1 = i61;
		*p = *i17 + d__1 * d__1 / (*i17 * 2.) - i61 / 2.;
	    }
	}
    }
    return 0;
} /* o27_ */

doublereal o25_(doublereal *i4)
{
    /* System generated locals */
    doublereal ret_val;

    /* Parameter adjustments */
    --i4;

    /* Function Body */
    i4[1] += i4[2];
    if (i4[2] < .5) {
	i4[1] += .123456789;
    }
    if (i4[1] > 1.) {
	i4[1] += -1.;
    }
    ret_val = i4[2];
    i4[2] = i4[1];
    i4[1] = ret_val;
    return ret_val;
} /* o25_ */

/* Subroutine */ int o29_(integer *i6, integer *i99, integer *i18, integer *
	i29, integer *i28, integer *i24, integer *i22)
{
    /* Parameter adjustments */
    --i6;

    /* Function Body */
    if (i6[*i18] == 1 && i6[*i22] == 1) {
	i6[*i29] = i6[*i24];
    } else {
	i6[*i29] = i6[*i28];
    }
    if (i6[*i18] <= i6[*i22] && i6[*i22] > 1) {
	i6[*i29] = i6[*i28] + (i6[*i24] - i6[*i28]) * (integer) ((doublereal) 
		(i6[*i18] - 1) / (doublereal) (i6[*i22] - 1));
    }
    if (i6[*i18] > i6[*i22] && i6[*i18] < i6[*i22] << 1) {
	i6[*i29] = i6[*i24];
	i6[*i29] += (i6[*i28] - i6[*i24]) * (integer) ((doublereal) i6[*i18] /
		 (doublereal) (i6[*i22] << 1));
	i6[*i29] <<= 1;
    }
    return 0;
} /* o29_ */

/* Subroutine */ int precheck_(integer *f, integer *o, integer *m, integer *n,
	 integer *i32, integer *i99, integer *fpl, doublereal *pl, doublereal 
	*i48, integer *i42, integer *i41)
{
    /* System generated locals */
    integer i__1;
    doublereal d__1;

    /* Builtin functions */
    integer i_dnnt(doublereal *);

    /* Local variables */
    static integer i__, p, k16, i302, i303;

    /* Parameter adjustments */
    --i48;
    --pl;

    /* Function Body */
    p = *f;
    i302 = *m * 120 + *n * 20 + *o * 20 + p * 20 + p * (*n + (*o << 1)) + *o *
	     *o + 4990;
    i303 = *m * 3 + p + 990;
    if (*i32 < i302) {
	*i42 = 501;
	goto L701;
    }
    if (*i99 < i303) {
	*i42 = 601;
	goto L701;
    }
    if (*o == 1) {
	return 0;
    }
    if (*o <= 0 || *o > 1000000) {
	*i42 = 101;
	goto L701;
    }
    if (abs(i48[10]) > 1e99) {
	*i42 = 321;
	goto L701;
    }
    if ((d__1 = i48[10] - (doublereal) i_dnnt(&i48[10]), abs(d__1)) > 1e-4) {
	*i42 = 322;
	goto L701;
    }
    if (i48[11] < 0. || i48[11] > .5) {
	*i42 = 331;
	goto L701;
    }
    k16 = 1000;
    if (abs(i48[10]) >= 1.) {
	d__1 = abs(i48[10]);
	k16 = i_dnnt(&d__1);
    }
    if (*fpl < k16 * (*o + *n + *m) + 1) {
	*i42 = 344;
	goto L701;
    } else {
	i__1 = *fpl;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    pl[i__] = 0.;
	}
    }
    return 0;
L701:
    *i41 = 1;
    return 0;
} /* precheck_ */

/* Subroutine */ int o30_(integer *m, integer *i8, doublereal *g, doublereal *
	i5, doublereal *i2, doublereal *i4, integer *i32)
{
    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    double d_nint(doublereal *);

    /* Local variables */
    static integer i__;
    extern doublereal o25_(doublereal *);

    /* Parameter adjustments */
    --i2;
    --i5;
    --g;
    --i4;

    /* Function Body */
    i__1 = *m;
    for (i__ = 1; i__ <= i__1; ++i__) {
	g[i__] = i5[i__] + o25_(&i4[1]) * (i2[i__] - i5[i__]);
	if (i__ > *m - *i8) {
	    g[i__] = d_nint(&g[i__]);
	}
    }
    return 0;
} /* o30_ */

/* Subroutine */ int o31_(doublereal *i17, doublereal *x, integer *n, integer 
	*i0, doublereal *i16)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__;

    /* Parameter adjustments */
    --x;

    /* Function Body */
    *i17 = 0.;
    if (*n == 0) {
	return 0;
    }
    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (x[i__] < -(*i16)) {
	    *i17 -= x[i__];
	}
    }
    i__1 = *i0;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (x[i__] > *i16) {
	    *i17 += x[i__];
	}
    }
    return 0;
} /* o31_ */

/* Subroutine */ int o5_(integer *i67, doublereal *g)
{
    /* Parameter adjustments */
    --g;

    /* Function Body */
    if (*i67 == 1) {
	g[1] = 1.620528056843441;
	g[2] = .638605421889285;
	g[3] = .906976035018917;
	g[4] = .011810145517119;
	g[5] = 1108.008277088986006;
	g[6] = 29.85306084632246;
	g[7] = 965.543098981308958;
	g[8] = .153567448330989;
	g[9] = .536446913343133;
	g[10] = 0.;
	g[11] = 1.8554463035e-5;
	g[12] = 0.;
	g[13] = 0.;
	g[14] = .528480646668186;
	g[15] = 52.279446588670019;
	g[16] = 8.99140433198839;
	g[17] = 0.;
	g[18] = 118.;
	g[19] = 1.;
	g[20] = 9.;
	g[21] = 20.;
	g[22] = 3.;
	g[23] = 10.;
	g[24] = 11.;
	g[25] = 2.;
	g[26] = 12.;
	g[27] = 154.;
	g[28] = 9.;
	g[29] = 126.;
	g[30] = 6.;
	g[31] = 35.;
	g[32] = 5294.;
	g[33] = 7.;
    }
    if (*i67 == 2) {
	g[1] = 1.12698190995684;
	g[2] = .215467789246713;
	g[3] = .278009658205816;
	g[4] = .755676178051916;
	g[5] = 365.871503777953478;
	g[6] = .01;
	g[7] = 675.436397307741117;
	g[8] = .305034750580056;
	g[9] = .422576324023031;
	g[10] = .016707520489292;
	g[11] = 1.36844918e-7;
	g[12] = .002804084004182;
	g[13] = 0.;
	g[14] = 0.;
	g[15] = 1.;
	g[16] = 5.242808042306666;
	g[17] = 0.;
	g[18] = 30.;
	g[19] = 1.;
	g[20] = 2.;
	g[21] = 93.;
	g[22] = 9.;
	g[23] = 7.;
	g[24] = 7.;
	g[25] = 5.;
	g[26] = 4.;
	g[27] = 625.;
	g[28] = 32.;
	g[29] = 103.;
	g[30] = 10.;
	g[31] = 14.;
	g[32] = 2892.;
	g[33] = 1.;
    }
    if (*i67 == 3) {
	g[1] = .96595994;
	g[2] = .00853917;
	g[3] = .99833462;
	g[4] = .01778501;
	g[5] = 1438.19523103;
	g[6] = 215.84206308;
	g[7] = 37.31750375;
	g[8] = .45492583;
	g[9] = .98223778;
	g[10] = .03113068;
	g[11] = 1.13e-5;
	g[12] = 0.;
	g[13] = .03093427;
	g[14] = .30711336;
	g[15] = 29.78066475;
	g[16] = 4.01315599;
	g[17] = 1.;
	g[18] = 56.17999408;
	g[19] = 39.51648992;
	g[20] = 25.39908456;
	g[21] = 38.27266273;
	g[22] = 11.82300928;
	g[23] = 4.84215525;
	g[24] = 11.8292433;
	g[25] = 8.96002292;
	g[26] = 15.63757862;
	g[27] = 1919.54310583;
	g[28] = 6.34093718;
	g[29] = 141.66662969;
	g[30] = 1.09400861;
	g[31] = 1.98867313;
	g[32] = 11989.588982;
	g[33] = 3.46998668;
    }
    return 0;
} /* o5_ */

/* Subroutine */ int o32_(integer *f, integer *m, integer *i8, doublereal *g, 
	doublereal *i5, doublereal *i2, integer *i19, integer *i49, 
	doublereal *i4, integer *i32, integer *i6, integer *i99, integer *i42,
	 integer *i93, doublereal *k3, integer *i36)
{
    /* Initialized data */

    static integer i10 = 0;
    static integer i43 = 0;
    static integer i21 = 0;
    static integer i39 = 0;
    static integer i62 = 0;
    static integer i38 = 0;
    static integer i20 = 0;
    static doublereal i35 = 0.;

    /* System generated locals */
    integer i__1;
    doublereal d__1;

    /* Builtin functions */
    double sqrt(doublereal), d_nint(doublereal *);

    /* Local variables */
    static integer i__, j, i95, i71;
    extern doublereal o25_(doublereal *);
    extern integer i301_(doublereal *, doublereal *);

    /* Parameter adjustments */
    --i2;
    --i5;
    --g;
    --i4;
    --i6;
    --k3;
    --i36;

    /* Function Body */
    if (*i42 == -30) {
	i10 = 0;
	i43 = *f + 32;
	i__1 = *m;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    j = (integer) (i__ * o25_(&i4[1])) + 1;
	    i6[i43 + i__ - 1] = i6[i43 + j - 1];
	    i6[i43 + j - 1] = i__;
	}
	i6[31] = 1;
	i38 = i43 + *m;
	i__1 = *m;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    i6[i38 + i__ - 1] = 0;
	}
	if (i4[1] >= .9) {
	    if ((d__1 = i4[8] * 3. - 6153., abs(d__1)) > .5) {
		i__1 = *i99;
		for (i__ = 1; i__ <= i__1; ++i__) {
		    i4[i__] = (doublereal) i6[i__];
		}
		*i42 = (integer) i4[1] * 1000;
		goto L22;
	    }
	}
    }
    i95 = 0;
    if (i6[31] == 0) {
	i20 = i6[i43 + i10 - 1];
	i6[30] = i20;
	++i39;
	i21 = -i21;
	i35 /= k3[6];
	if (i35 < 1. / (doublereal) (i36[7] * 10)) {
	    i35 = 1. / (doublereal) (i36[7] * 10);
	}
	if (i20 > *m - *i8 && i39 > i62) {
	    i6[i38 + i20 - 1] = 1;
	    if (i10 >= *m) {
		goto L2;
	    }
	    i95 = 1;
	}
	i71 = i36[8];
	if (i20 <= *m - *i8 && i39 > i71) {
	    i6[i38 + i20 - 1] = 1;
	    if (i10 >= *m) {
		goto L2;
	    }
	    i95 = 1;
	}
	if ((d__1 = i5[i20] - i2[i20], abs(d__1)) <= 1e-12) {
	    i6[i38 + i20 - 1] = 1;
	    if (i10 >= *m) {
		goto L2;
	    }
	    i95 = 1;
	}
    }
    if (i6[31] == 1 || i95 == 1) {
	++i10;
	if (i10 > *m) {
	    goto L2;
	}
	i20 = i6[i43 + i10 - 1];
	i6[30] = i20;
	i39 = 1;
	if (i20 > *m - *i8) {
	    if (i301_(&i4[*i19 + i20 - 1], &i5[i20]) == 1 || i301_(&i4[*i19 + 
		    i20 - 1], &i2[i20]) == 1) {
		i62 = 1;
	    } else {
		i62 = 2;
	    }
	}
	if (o25_(&i4[1]) >= .5) {
	    i21 = 1;
	} else {
	    i21 = -1;
	}
	i35 = sqrt(i4[*i49 + i20 - 1]);
    }
    i__1 = *m;
    for (i__ = 1; i__ <= i__1; ++i__) {
	g[i__] = i4[*i19 + i__ - 1];
    }
    if (i20 <= *m - *i8) {
	g[i20] += i21 * i35;
    } else {
	g[i20] += i21;
	if (g[i20] < i5[i20]) {
	    g[i20] = i5[i20] + 1;
	}
	if (g[i20] > i2[i20]) {
	    g[i20] = i2[i20] - 1;
	}
    }
    if (g[i20] < i5[i20]) {
	g[i20] = i5[i20];
    }
    if (g[i20] > i2[i20]) {
	g[i20] = i2[i20];
    }
    if (i20 > *m - *i8) {
	g[i20] = d_nint(&g[i20]);
    }
    if (i10 == 1 && i39 == 1) {
	*i42 = -30;
    } else {
	*i42 = -31;
    }
    return 0;
L2:
    *i42 = -40;
    i__1 = *m;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (i6[i38 + i__ - 1] == 0) {
	    goto L22;
	}
    }
    *i93 = 1;
    *i42 = -99;
L22:
    return 0;
} /* o32_ */

/* Subroutine */ int midaco_kernel_driver__(integer *p, integer *o, integer *
	m, integer *i8, integer *n, integer *i0, doublereal *l, doublereal *x,
	 doublereal *g, doublereal *i5, doublereal *i2, integer *i42, integer 
	*i41, doublereal *i48, doublereal *i4, integer *i32, integer *i6, 
	integer *i99, doublereal *pl, integer *fpl, integer *ea, integer *eb, 
	integer *edx, integer *edl, integer *eu, integer *em, integer *eie, 
	integer *en, integer *eln, char *i15, ftnlen i15_len)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer c__, i__;
    extern /* Subroutine */ int io7_lomfy__(doublereal *, integer *), o12_(
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, integer *, integer *, doublereal *, doublereal *, 
	    integer *, integer *, integer *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, char *, 
	    ftnlen), o15_(integer *, integer *, integer *, integer *, integer 
	    *, integer *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, integer *, integer *, doublereal *, 
	    doublereal *, integer *, integer *, integer *, doublereal *, 
	    doublereal *, doublereal *, char *, ftnlen), io7_(doublereal *, 
	    doublereal *, integer *, integer *);

    /* Parameter adjustments */
    --i2;
    --i5;
    --l;
    --x;
    --g;
    --i48;
    --i4;
    --i6;
    --pl;

    /* Function Body */
    if (*i42 == -999) {
	*i41 = 1;
    }
    i__1 = *p;
    for (c__ = 1; c__ <= i__1; ++c__) {
	if (*n <= 0) {
	    io7_lomfy__(&l[(c__ - 1) * *o + 1], o);
	} else {
	    io7_(&l[(c__ - 1) * *o + 1], &x[(c__ - 1) * *n + 1], o, n);
	}
    }
    if (*o <= 1) {
	if (*n > 0) {
	    i__1 = *p * *n;
	    for (i__ = 1; i__ <= i__1; ++i__) {
		i4[*edx + i__ - 1] = x[i__];
	    }
	    i4[*edx + *p * *n] = 0.;
	} else {
	    i4[*edx] = 0.;
	}
	o15_(p, o, m, i8, n, i0, &g[1], &l[1], &i4[*edx], &i5[1], &i2[1], i42,
		 i41, &i48[1], &i4[1], i32, &i6[1], i99, &i4[*ea], &i4[*eb], &
		i4[*eie], i15, (ftnlen)60);
    } else {
	o12_(p, o, m, i8, n, i0, &g[1], &l[1], &x[1], &i5[1], &i2[1], i42, 
		i41, &i48[1], &i4[1], i32, &i6[1], i99, &pl[1], &i4[*ea], &i4[
		*eb], &i4[*edx], &i4[*edl], &i4[*eu], &i4[*em], &i4[*eie], &
		i4[*en], &i4[*eln], i15, (ftnlen)60);
    }
    if (*i41 == 1) {
	i__1 = *n;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    x[i__] = i4[*edx + i__ - 1];
	}
    }
    return 0;
} /* midaco_kernel_driver__ */

/* Subroutine */ int o33_(integer *i12, integer *i29, integer *k, integer *
	i18, integer *i13, integer *i28, integer *i24, integer *i22)
{
    *k = 1;
    *i12 = 2;
    *i29 = 3;
    *i18 = 4;
    *i13 = 5;
    *i28 = 6;
    *i24 = 7;
    *i22 = 8;
    return 0;
} /* o33_ */

/* Subroutine */ int o34_(integer *m, integer *n, integer *i31, integer *i27, 
	integer *i23, integer *i66, integer *i45, integer *i30, integer *i19, 
	integer *i14, integer *i40, integer *i11, integer *w, integer *i49, 
	integer *i9, integer *i1, integer *i7, integer *i170)
{
    *i31 = 10;
    *i27 = *i31 + *m;
    *i23 = *i27 + 1;
    *i66 = *i23 + *n;
    *i45 = *i66 + 1;
    *i19 = *i45 + 1;
    *i14 = *i19 + *m * *i30;
    *i40 = *i14 + *i30;
    *i11 = *i40 + *i30;
    *i9 = *i11 + *i30;
    *w = *i9 + *i30 + 1;
    *i49 = *w + *i30;
    *i1 = *i49 + *m;
    *i7 = *i1 + 1;
    *i170 = *i7 + 1;
    return 0;
} /* o34_ */

/* Subroutine */ int o35_(integer *m, integer *i8, doublereal *g, doublereal *
	i5, doublereal *i2, doublereal *i4, integer *i32, integer *i31, 
	doublereal *i47, doublereal *k3)
{
    /* System generated locals */
    integer i__1;
    doublereal d__1;

    /* Builtin functions */
    double sqrt(doublereal), d_nint(doublereal *);

    /* Local variables */
    static integer i__;
    static doublereal i34, i35;
    extern doublereal o25_(doublereal *), o16_(doublereal *, doublereal *);

    /* Parameter adjustments */
    --i2;
    --i5;
    --g;
    --i4;
    --k3;

    /* Function Body */
    i__1 = *m;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i35 = (i2[i__] - i5[i__]) / *i47;
	if (i__ > *m - *i8) {
	    if (i35 < 1. / sqrt(*i47)) {
		i35 = 1. / sqrt(*i47);
	    }
	}
	i34 = o25_(&i4[1]);
	d__1 = o25_(&i4[1]);
	g[i__] = i4[*i31 + i__ - 1] + i35 * o16_(&i34, &d__1);
	if (g[i__] < i5[i__]) {
	    if (i34 >= k3[2]) {
		g[i__] = i5[i__] + (i5[i__] - g[i__]) * k3[3];
		if (g[i__] > i2[i__]) {
		    g[i__] = i2[i__];
		}
	    } else {
		g[i__] = i5[i__];
	    }
	    goto L2;
	}
	if (g[i__] > i2[i__]) {
	    if (i34 >= k3[2]) {
		g[i__] = i2[i__] - (g[i__] - i2[i__]) * k3[3];
		if (g[i__] < i5[i__]) {
		    g[i__] = i5[i__];
		}
	    } else {
		g[i__] = i2[i__];
	    }
	}
L2:
	if (i__ > *m - *i8) {
	    g[i__] = d_nint(&g[i__]);
	}
    }
    return 0;
} /* o35_ */

/* Subroutine */ int o13_(integer *f, integer *c__, integer *m, doublereal *
	i4, integer *i32, integer *i6, integer *i99, integer *i19, integer *
	i14, integer *i40, integer *i11, doublereal *g, doublereal *l, 
	doublereal *i17, doublereal *p, integer *i36)
{
    /* System generated locals */
    integer i__1;
    doublereal d__1, d__2;

    /* Builtin functions */
    double pow_dd(doublereal *, doublereal *);

    /* Local variables */
    static integer i__;

    /* Parameter adjustments */
    --g;
    --i4;
    --i6;
    --i36;

    /* Function Body */
    if (*i17 <= 0. && i4[*i40] <= 0.) {
	d__2 = (doublereal) i36[5];
	if (*l >= i4[*i14] - (d__1 = i4[*i14], abs(d__1)) / (pow_dd(&c_b27, &
		d__2) + (doublereal) (*m))) {
	    i6[*c__ + 31] = 0;
	    goto L1;
	}
    } else {
	d__2 = (doublereal) i36[5];
	if (*p >= i4[*i11] - (d__1 = i4[*i11], abs(d__1)) / (pow_dd(&c_b27, &
		d__2) + (doublereal) (*m))) {
	    i6[*c__ + 31] = 0;
	    goto L1;
	}
    }
    i__1 = *m;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i4[*i19 + i__ - 1] = g[i__];
    }
    i4[*i40] = *i17;
    i4[*i14] = *l;
    i4[*i11] = *p;
    i6[*c__ + 31] = 1;
L1:
    if (*c__ == *f) {
	i6[31] = 0;
	i__1 = *f;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    i6[31] += i6[i__ + 31];
	}
	if (i6[31] > 1) {
	    i6[31] = 1;
	}
    }
    return 0;
} /* o13_ */

/* Subroutine */ int o1_(integer *o, doublereal *l, doublereal *i17, 
	doublereal *i16, doublereal *i306, doublereal *i307, doublereal *io9, 
	doublereal *g004, doublereal *g008, doublereal *g015, integer *g005)
{
    /* System generated locals */
    integer i__1;
    doublereal d__1;

    /* Local variables */
    static integer activeobjectives, i__;
    static doublereal k4t[1000], io22, fx17;

    /* Parameter adjustments */
    --g008;
    --i307;
    --i306;
    --l;

    /* Function Body */
    if (*io9 >= 1.) {
	i__ = (integer) (*io9);
	*g015 = l[i__];
	goto L999;
    }
    if (*g005 == 1) {
	*g015 = 0.;
	i__1 = *o;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    if (g008[i__] > 0.) {
		*g015 += (d__1 = l[i__], abs(d__1));
	    }
	}
	goto L999;
    }
    if (*i17 > *i16) {
	*g015 = 1.;
	i__1 = *o;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    if (g008[i__] > 0.) {
		*g015 += (d__1 = l[i__], abs(d__1));
	    }
	}
	goto L999;
    }
    io22 = 0.;
    i__1 = *o;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (i306[i__] < i307[i__]) {
	    k4t[i__ - 1] = g008[i__] * (l[i__] - i306[i__]) / (i307[i__] - 
		    i306[i__]);
	} else {
	    k4t[i__ - 1] = g008[i__] * (l[i__] - i306[i__]);
	}
	io22 += k4t[i__ - 1];
    }
    activeobjectives = 0;
    i__1 = *o;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (g008[i__] > 0.) {
	    ++activeobjectives;
	}
    }
    fx17 = 0.;
    i__1 = *o;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (g008[i__] > 0.) {
	    fx17 += (d__1 = k4t[i__ - 1] - io22 / (doublereal) 
		    activeobjectives, abs(d__1));
	}
    }
    *g015 = io22 + fx17 + *g004;
L999:
    return 0;
} /* o1_ */

/* Subroutine */ int o36_(integer *m, integer *k, doublereal *i4, integer *
	i32, integer *i19, integer *i14, integer *i40, integer *i11, 
	doublereal *g, doublereal *l, doublereal *i17, doublereal *p)
{
    /* System generated locals */
    integer i__1, i__2;

    /* Local variables */
    static integer i__, j, io24;

    /* Parameter adjustments */
    --g;
    --i4;

    /* Function Body */
    if (*p >= i4[*i11 + *k - 1]) {
	return 0;
    }
    io24 = 0;
    i__1 = *k;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (*p <= i4[*i11 + *k - i__]) {
	    io24 = *k - i__ + 1;
	} else {
	    goto L567;
	}
    }
L567:
    i__1 = *k - io24;
    for (j = 1; j <= i__1; ++j) {
	i__2 = *m;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    i4[*i19 + (*k - j) * *m + i__ - 1] = i4[*i19 + (*k - j - 1) * *m 
		    + i__ - 1];
	}
	i4[*i14 + *k - j] = i4[*i14 + *k - j - 1];
	i4[*i40 + *k - j] = i4[*i40 + *k - j - 1];
	i4[*i11 + *k - j] = i4[*i11 + *k - j - 1];
    }
    i__1 = *m;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i4[*i19 + (io24 - 1) * *m + i__ - 1] = g[i__];
    }
    i4[*i14 + io24 - 1] = *l;
    i4[*i40 + io24 - 1] = *i17;
    i4[*i11 + io24 - 1] = *p;
    return 0;
} /* o36_ */

/* Subroutine */ int o3_(integer *i67, doublereal *g)
{
    /* Parameter adjustments */
    --g;

    /* Function Body */
    if (*i67 == 1) {
	g[1] = 39.865764264129574;
	g[2] = .010570703057877;
	g[3] = .594035921462431;
	g[4] = .025981010462433;
	g[5] = 6951.349708195207313;
	g[6] = 196.588335760200493;
	g[7] = 494.652510416191831;
	g[8] = 0.;
	g[9] = .262888955891235;
	g[10] = .118645304605935;
	g[11] = 9.8583337437e-4;
	g[12] = 0.;
	g[13] = .982333333335689;
	g[14] = .266202592278773;
	g[15] = 107.75061518337175;
	g[16] = 4.221215621644779;
	g[17] = 0.;
	g[18] = 35.;
	g[19] = 41.;
	g[20] = 7.;
	g[21] = 183.;
	g[22] = 10.;
	g[23] = 1.;
	g[24] = 6.;
	g[25] = 2.;
	g[26] = 16.;
	g[27] = 76.;
	g[28] = 2.;
	g[29] = 194.;
	g[30] = 11.;
	g[31] = 75.;
	g[32] = 85851.;
	g[33] = 9.;
    }
    if (*i67 == 2) {
	g[1] = 88.378305246891642;
	g[2] = .596671879892428;
	g[3] = .96238124550318;
	g[4] = 3.812970488946382;
	g[5] = 3555.889503794543998;
	g[6] = 284.029023525477442;
	g[7] = 278.15945695917793;
	g[8] = .467000314148584;
	g[9] = .755952269574951;
	g[10] = .103963081719344;
	g[11] = 0.;
	g[12] = 0.;
	g[13] = .034604619091198;
	g[14] = .447568930956009;
	g[15] = 112.349387854963524;
	g[16] = 7.661018416622316;
	g[17] = 0.;
	g[18] = 7.;
	g[19] = 37.;
	g[20] = 2.;
	g[21] = 354.;
	g[22] = 3.;
	g[23] = 8.;
	g[24] = 9.;
	g[25] = 2.;
	g[26] = 8.;
	g[27] = 1925.;
	g[28] = 63.;
	g[29] = 281.;
	g[30] = 6.;
	g[31] = 44.;
	g[32] = 17294.;
	g[33] = 23.;
    }
    if (*i67 == 3) {
	g[1] = 1.00449566;
	g[2] = .01859477;
	g[3] = .97719994;
	g[4] = 1.07101045;
	g[5] = 1345.89422853;
	g[6] = 185.25796624;
	g[7] = 454.99070924;
	g[8] = .4030333;
	g[9] = .98286025;
	g[10] = .0718894;
	g[11] = 3.131e-5;
	g[12] = 0.;
	g[13] = .20107243;
	g[14] = .32253905;
	g[15] = 28.95573242;
	g[16] = 4.35016847;
	g[17] = 1.;
	g[18] = 59.94655842;
	g[19] = 10.40235209;
	g[20] = 45.5960256;
	g[21] = 5.33303639;
	g[22] = 11.0260158;
	g[23] = 5.62258459;
	g[24] = 11.8758362;
	g[25] = 9.03405164;
	g[26] = 3.54369856;
	g[27] = 1555.70240325;
	g[28] = 3.27561139;
	g[29] = 280.72701458;
	g[30] = 1.6899118;
	g[31] = 7.72937078;
	g[32] = 2162.86269813;
	g[33] = 5.22324273;
    }
    return 0;
} /* o3_ */

/* Subroutine */ int o37_(integer *k, doublereal *i4, integer *i32, integer *
	w)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer j, i57;

    /* Parameter adjustments */
    --i4;

    /* Function Body */
    i57 = 0;
    i__1 = *k;
    for (j = 1; j <= i__1; ++j) {
	i57 += j;
    }
    i__1 = *k;
    for (j = 1; j <= i__1; ++j) {
	i4[*w + j - 1] = (doublereal) (*k - j + 1) / (doublereal) i57;
    }
    return 0;
} /* o37_ */

/* Subroutine */ int o28_(integer *m, integer *i8, integer *k, doublereal *g, 
	doublereal *i5, doublereal *i2, doublereal *i4, integer *i32, integer 
	*i19, integer *i49, integer *i9, doublereal *k3)
{
    /* System generated locals */
    integer i__1, i__2;

    /* Builtin functions */
    double d_nint(doublereal *);

    /* Local variables */
    static integer i__, j, q, r__, s, t;
    static doublereal u, v;
    static integer w;
    static doublereal z__, i34, k32, k33;
    extern /* Subroutine */ int o10_(integer *, integer *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, integer *);
    extern doublereal o25_(doublereal *), o16_(doublereal *, doublereal *);
    static doublereal i2i, i5i;

    /* Parameter adjustments */
    --k3;
    --i4;
    --i2;
    --i5;
    --g;

    /* Function Body */
    u = i4[*i9 + 1];
    v = i4[*i9 + 2];
    q = *k - 1;
    r__ = *i49 - 1;
    s = *i19 - 1;
    t = s + *m;
    w = s - *m;
    k32 = k3[2];
    k33 = k3[3];
    i__1 = *m;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i34 = o25_(&i4[1]);
	z__ = i4[r__ + i__] * o16_(&i4[1], &i4[2]);
	if (i34 <= u) {
	    z__ += i4[s + i__];
	} else {
	    if (i34 <= v) {
		z__ += i4[t + i__];
	    } else {
		i__2 = q;
		for (j = 3; j <= i__2; ++j) {
		    if (i34 <= i4[*i9 + j]) {
			goto L1;
		    }
		}
L1:
		z__ += i4[w + j * *m + i__];
	    }
	}
	i5i = i5[i__];
	i2i = i2[i__];
	if (z__ < i5i) {
	    if (i34 >= k32) {
		z__ = i5i + (i5i - z__) * k33;
		if (z__ > i2i) {
		    z__ = i2i;
		}
	    } else {
		z__ = i5i;
	    }
	    goto L2;
	}
	if (z__ > i2i) {
	    if (i34 >= k32) {
		z__ = i2i - (z__ - i2i) * k33;
		if (z__ < i5i) {
		    z__ = i5i;
		}
	    } else {
		z__ = i2i;
	    }
	}
L2:
	g[i__] = z__;
    }
    if (*i8 <= 0) {
	return 0;
    }
    i__1 = *m;
    for (i__ = *m - *i8 + 1; i__ <= i__1; ++i__) {
	g[i__] = d_nint(&g[i__]);
    }
    if (*i8 < *m) {
	return 0;
    }
    r__ = *i19 - 1 - *m;
    i__1 = *k;
    for (j = 1; j <= i__1; ++j) {
	s = r__ + j * *m;
	i__2 = *m;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    t = s + i__;
	    if (g[i__] < i4[t]) {
		goto L88;
	    }
	    if (g[i__] > i4[t]) {
		goto L88;
	    }
	}
	o10_(m, i8, &g[1], &i5[1], &i2[1], &i4[1], i32);
	return 0;
L88:
	;
    }
    return 0;
} /* o28_ */

/* Subroutine */ int k22_(integer *f, integer *m, integer *n, integer *i0, 
	doublereal *l, doublereal *x, doublereal *g, doublereal *i16)
{
    /* System generated locals */
    integer i__1, i__2;

    /* Local variables */
    static integer c__, i__, k23;
    static doublereal i17, k24, i56;
    extern /* Subroutine */ int o31_(doublereal *, doublereal *, integer *, 
	    integer *, doublereal *);

    /* Parameter adjustments */
    --g;
    --x;
    --l;

    /* Function Body */
    if (*f <= 1) {
	return 0;
    }
    if (*n <= 0) {
	i56 = l[1];
	k23 = 1;
	i__1 = *f;
	for (c__ = 2; c__ <= i__1; ++c__) {
	    if (l[c__] < i56) {
		i56 = l[c__];
		k23 = c__;
	    }
	}
    }
    if (*n >= 1) {
	o31_(&i17, &x[1], n, i0, i16);
	i56 = l[1];
	k24 = i17;
	k23 = 1;
	i__1 = *f;
	for (c__ = 2; c__ <= i__1; ++c__) {
	    o31_(&i17, &x[(c__ - 1) * *n + 1], n, i0, i16);
	    if (k24 <= 0.) {
		if (i17 <= 0. && l[c__] < i56) {
		    i56 = l[c__];
		    k24 = i17;
		    k23 = c__;
		}
	    } else {
		if (i17 < k24) {
		    i56 = l[c__];
		    k24 = i17;
		    k23 = c__;
		}
	    }
	}
    }
    i__1 = *f;
    for (c__ = 1; c__ <= i__1; ++c__) {
	l[c__] = l[k23];
	i__2 = *n;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    x[(c__ - 1) * *n + i__] = x[(k23 - 1) * *n + i__];
	}
	i__2 = *m;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    g[(c__ - 1) * *m + i__] = g[(k23 - 1) * *m + i__];
	}
    }
    return 0;
} /* k22_ */

/* Subroutine */ int o9_(doublereal *g004, doublereal *g019, doublereal *io23,
	 integer *o, integer *g005, integer *io10, doublereal *io16)
{
    /* System generated locals */
    doublereal d__1, d__2;

    /* Builtin functions */
    double sqrt(doublereal), pow_dd(doublereal *, doublereal *);

    /* Local variables */
    extern doublereal rio5_(doublereal *, doublereal *);

    *io10 = 1;
    *io16 = 0.;
    if ((d__1 = *g019 - *io23, abs(d__1)) < 1e32) {
	if ((d__1 = *g019 - *io23, abs(d__1)) > 1.) {
	    if (*o <= 2) {
		d__2 = (doublereal) (*g005);
		*g004 -= sqrt((d__1 = *g019 - *io23, abs(d__1))) / pow_dd(&
			d__2, &c_b141);
	    } else {
		*g004 -= sqrt((d__1 = *g019 - *io23, abs(d__1)));
	    }
	} else {
	    *g004 -= (d__1 = *g019 - *io23, abs(d__1));
	}
	*io16 = rio5_(g019, io23);
    } else {
	*g004 += -1.;
    }
    return 0;
} /* o9_ */

/* Subroutine */ int o6_(integer *o, doublereal *g008, doublereal *io9)
{
    /* System generated locals */
    integer i__1;
    doublereal d__1;

    /* Builtin functions */
    double pow_dd(doublereal *, doublereal *);

    /* Local variables */
    static integer maxobji67, i__;
    extern integer i301_(doublereal *, doublereal *);
    static doublereal g018;
    extern doublereal io27_(doublereal *);
    static doublereal i17t, fx25, fx26, sung;

    /* Parameter adjustments */
    --g008;

    /* Function Body */
    i__1 = *o;
    for (i__ = 1; i__ <= i__1; ++i__) {
	g008[i__] = 1.;
    }
    if (i301_(io9, &c_b14) == 1) {
	goto L999;
    }
    if (*io9 >= 1.) {
	goto L999;
    }
    i__1 = *o;
    for (i__ = 1; i__ <= i__1; ++i__) {
	g008[i__] = 0.;
    }
    maxobji67 = min(*o,8);
    i__1 = maxobji67;
    for (i__ = 1; i__ <= i__1; ++i__) {
	d__1 = (doublereal) (i__ - 1);
	g018 = *io9 * pow_dd(&c_b27, &d__1);
	g018 -= io27_(&g018);
	g018 *= 10.;
	i17t = g018 - io27_(&g018);
	if (i17t > .99999999) {
	    g018 += 1;
	}
	g018 -= i17t;
	g008[i__] = g018;
    }
    sung = 0.;
    i__1 = maxobji67;
    for (i__ = 1; i__ <= i__1; ++i__) {
	sung += g008[i__];
    }
    i__1 = maxobji67;
    for (i__ = 1; i__ <= i__1; ++i__) {
	g008[i__] /= sung;
    }
    fx25 = 0.;
    i__1 = maxobji67;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (g008[i__] > fx25) {
	    fx25 = g008[i__];
	}
    }
    fx26 = 1. / fx25;
    if (fx26 > 1.) {
	i__1 = maxobji67;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    g008[i__] *= fx26;
	}
    }
L999:
    return 0;
} /* o6_ */

/* Subroutine */ int o10_(integer *m, integer *i8, doublereal *g, doublereal *
	i5, doublereal *i2, doublereal *i4, integer *i32)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__;
    extern /* Subroutine */ int o30_(integer *, integer *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, integer *);
    extern doublereal o25_(doublereal *);
    static integer g017;
    static doublereal io6;

    /* Parameter adjustments */
    --i4;
    --i2;
    --i5;
    --g;

    /* Function Body */
    io6 = 1. / (doublereal) (*m);
    g017 = 0;
    i__1 = *m;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (i5[i__] >= i2[i__]) {
	    goto L1;
	}
	if (o25_(&i4[1]) <= io6) {
	    if (g[i__] <= i5[i__]) {
		g[i__] = i5[i__] + 1.;
		g017 = 1;
		goto L1;
	    }
	    if (g[i__] >= i2[i__]) {
		g[i__] = i2[i__] - 1.;
		g017 = 1;
		goto L1;
	    }
	    if (o25_(&i4[1]) <= .5) {
		g[i__] += -1.;
		g017 = 1;
	    } else {
		g[i__] += 1.;
		g017 = 1;
	    }
	}
L1:
	;
    }
    if (g017 == 0) {
	o30_(m, i8, &g[1], &i5[1], &i2[1], &i4[1], i32);
    }
    return 0;
} /* o10_ */

/* Subroutine */ int io17_(integer *o, integer *n, integer *m, doublereal *
	g014, doublereal *l, doublereal *x, doublereal *g, doublereal *i17, 
	doublereal *i16, doublereal *g001, doublereal *io1, doublereal *g002, 
	doublereal *pl, integer *k16, doublereal *i306, doublereal *i307, 
	doublereal *g008, doublereal *io9, integer *io4, integer *io20, 
	integer *io2, integer *io10, doublereal *io16, integer *g005)
{
    /* Initialized data */

    static integer i10ker = 0;

    /* System generated locals */
    integer i__1, i__2;
    doublereal d__1, d__2;

    /* Local variables */
    static integer i__, k;
    extern /* Subroutine */ int o1_(integer *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, integer *);
    static doublereal k6, t1, t2, t3, t4;
    static integer i431;
    extern doublereal i305_(void);
    static integer i432, i433;
    static doublereal i437;
    static integer i449;
    static doublereal k4t, fx07, fx19;
    extern doublereal rio5_(doublereal *, doublereal *);
    static integer best_i__;

    /* Parameter adjustments */
    --g008;
    --i307;
    --i306;
    --pl;
    --g002;
    --g;
    --x;
    --l;

    /* Function Body */
    if (*io9 >= 1.) {
	goto L999;
    }
    if (*i17 > *i16) {
	goto L999;
    }
    if (*io1 > *i16) {
	goto L999;
    }
    i449 = (integer) pl[1];
    if (i449 < 1) {
	goto L999;
    }
    k6 = .001;
    if (*io4 <= 1) {
	i10ker = 0;
	*io4 = 666;
    }
    ++i10ker;
    i431 = 2;
    i432 = *k16 * *o + 2;
    i433 = *k16 * *o + 1 + *k16 * *n + 1;
    if (*io10 == 1 && *io16 > .05) {
	goto L888;
    }
    i437 = 0.;
    t1 = 0.;
    i__1 = *o;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (g008[i__] > 0.) {
	    if (l[i__] < g002[i__]) {
		i437 += rio5_(&l[i__], &g002[i__]);
	    }
	    if (l[i__] > g002[i__]) {
		t1 += rio5_(&l[i__], &g002[i__]);
	    }
	}
    }
    if (i437 > 0. && t1 <= 0.) {
	if (*g014 >= *g001) {
	    *g014 = *g001 - abs(*g001) * 1e-8;
	}
	goto L888;
    }
    if (i437 <= 0. && t1 > 0.) {
	if (*g014 <= *g001) {
/* Computing MAX */
	    d__1 = 1., d__2 = abs(*g001);
	    *g014 = *g001 + t1 * max(d__1,d__2);
	}
	goto L999;
    }
    if (i437 <= 0. && t1 <= 0.) {
	if (*g014 > *g001) {
	    *g014 = *g001;
	}
	goto L999;
    }
    if (*io2 == 0 && i449 >= 1) {
	if (*g014 <= *g001) {
	    *g014 = *g001 + abs(*g001) * 1e-8;
	    goto L999;
	}
    }
    if (*io2 == 1 && i449 == 1) {
	if (*g014 >= *g001) {
	    *g014 = *g001 - abs(*g001) * 1e-8;
	    goto L999;
	}
    }
    if (*io20 >= 2 && *g014 > *g001) {
	goto L999;
    }
    if (*io2 == 1) {
	goto L1;
    }
    if (*g014 <= *g001) {
/* Computing MAX */
	d__1 = 1., d__2 = abs(*g001);
	*g014 = *g001 + k6 * max(d__1,d__2);
    }
    goto L999;
L1:
    fx19 = i305_();
    i__1 = i449;
    for (i__ = 1; i__ <= i__1; ++i__) {
	k4t = 0.;
	i__2 = *o;
	for (k = 1; k <= i__2; ++k) {
	    k4t += rio5_(&g002[k], &pl[i431 - 1 + *o * (i__ - 1) + k]);
	}
	if (k4t < fx19) {
	    fx19 = k4t;
	}
	if (k4t <= k6) {
	    goto L2;
	}
    }
    if (*g014 >= *g001) {
	*g014 = *g001 - abs(*g001) * 1e-8;
    }
    goto L888;
L2:
    o1_(o, &l[1], i17, i16, &i306[1], &i307[1], io9, &c_b14, &g008[1], &t2, 
	    g005);
    o1_(o, &g002[1], i17, i16, &i306[1], &i307[1], io9, &c_b14, &g008[1], &t3,
	     g005);
    if (*g014 > *g001 && t2 < t3) {
	*g014 = *g001 - abs(*g001) * 1e-8;
	goto L888;
    }
    if (*g014 < *g001 && t2 >= t3) {
	*g014 = *g001 + (d__1 = t2 - t3, abs(d__1));
	goto L999;
    }
    if (i10ker >= 10) {
	i10ker = 0;
	goto L888;
    }
L999:
    return 0;
L888:
    if (i449 < 3) {
	goto L999;
    }
    fx07 = i305_();
    best_i__ = 1;
    i__1 = i449;
    for (i__ = 1; i__ <= i__1; ++i__) {
	o1_(o, &pl[i431 - 1 + *o * (i__ - 1) + 1], i17, i16, &i306[1], &i307[
		1], io9, &c_b14, &g008[1], &t4, g005);
	if (t4 <= fx07) {
	    fx07 = t4;
	    best_i__ = i__;
	}
    }
    k4t = 0.;
    i__ = best_i__;
    i__1 = *o;
    for (k = 1; k <= i__1; ++k) {
	k4t += rio5_(&g002[k], &pl[i431 - 1 + *o * (i__ - 1) + k]);
    }
    if (k4t <= .05) {
    } else {
	i__1 = *o;
	for (k = 1; k <= i__1; ++k) {
	}
	i__1 = *o;
	for (k = 1; k <= i__1; ++k) {
	    l[k] = pl[i431 - 1 + *o * (best_i__ - 1) + k];
	}
	i__1 = *n;
	for (k = 1; k <= i__1; ++k) {
	    x[k] = pl[i432 - 1 + *n * (best_i__ - 1) + k];
	}
	i__1 = *m;
	for (k = 1; k <= i__1; ++k) {
	    g[k] = pl[i433 - 1 + *m * (best_i__ - 1) + k];
	}
	*g014 = *g001 - abs(*g001) * 1e-8;
    }
    return 0;
} /* io17_ */

/* Subroutine */ int t5_(integer *g016, integer *i67, integer *p, doublereal *
	z__)
{
    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    static integer i__;
    static doublereal i2[33], i5[33];
    extern /* Subroutine */ int io12_(integer *, doublereal *), io13_(integer 
	    *, doublereal *);
    static doublereal io14[33];
    static integer maxp;

    /* Parameter adjustments */
    --z__;

    /* Function Body */
    for (i__ = 1; i__ <= 33; ++i__) {
	io14[i__ - 1] = 0.;
    }
    if (*g016 == 1) {
	io13_(i67, io14);
    }
    if (*g016 == 2) {
	io12_(i67, io14);
    }
    maxp = min(*p,100);
    for (i__ = 1; i__ <= 33; ++i__) {
	z__[i__] += io14[i__ - 1] * (z__[i__] - z__[i__] / sqrt((doublereal) 
		maxp));
    }
    i5[0] = .1;
    i2[0] = 90.;
    i5[1] = 0.;
    i2[1] = 1.;
    i5[2] = 0.;
    i2[2] = 1.;
    i5[3] = 0.;
    i2[3] = 9.;
    i5[4] = .01;
    i2[4] = 9e3;
    i5[5] = .01;
    i2[5] = 500.;
    i5[6] = 1.;
    i2[6] = 5e3;
    i5[7] = 0.;
    i2[7] = 1.;
    i5[8] = 0.;
    i2[8] = 1.;
    i5[9] = 1e-12;
    i2[9] = .5;
    i5[10] = 0.;
    i2[10] = .001;
    i5[11] = 0.;
    i2[11] = 0.;
    i5[12] = 0.;
    i2[12] = .999;
    i5[13] = 0.;
    i2[13] = 1.;
    i5[14] = 1.;
    i2[14] = 500.;
    i5[15] = 4.;
    i2[15] = 12.;
    i5[16] = 0.;
    i2[16] = 0.;
    i5[17] = 2.;
    i2[17] = 200.;
    i5[18] = 1.;
    i2[18] = 1e3;
    i5[19] = 1.;
    i2[19] = 100.;
    i5[20] = 1.;
    i2[20] = 500.;
    i5[21] = 1.;
    i2[21] = 12.;
    i5[22] = 1.;
    i2[22] = 12.;
    i5[23] = 1.;
    i2[23] = 12.;
    i5[24] = 1.;
    i2[24] = 12.;
    i5[25] = 1.;
    i2[25] = 500.;
    i5[26] = 2.;
    i2[26] = 2e3;
    i5[27] = 2.;
    i2[27] = 100.;
    i5[28] = 2.;
    i2[28] = 2e3;
    i5[29] = 1.;
    i2[29] = 12.;
    i5[30] = 1.;
    i2[30] = 100.;
    i5[31] = 10.;
    i2[31] = 9e4;
    i5[32] = 1.;
    i2[32] = 30.;
    for (i__ = 1; i__ <= 33; ++i__) {
	if (z__[i__] < i5[i__ - 1]) {
	    z__[i__] = i5[i__ - 1];
	}
	if (z__[i__] > i2[i__ - 1]) {
	    z__[i__] = i2[i__ - 1];
	}
    }
    return 0;
} /* t5_ */

/* Subroutine */ int io13_(integer *i67, doublereal *g)
{
    /* Parameter adjustments */
    --g;

    /* Function Body */
    if (*i67 == 1) {
	g[1] = 4.29154553;
	g[2] = 1.47194224;
	g[3] = 1.54997898;
	g[4] = -.17704074;
	g[5] = -1.;
	g[6] = .56172152;
	g[7] = .05515924;
	g[8] = -.3771567;
	g[9] = 3.74633499;
	g[10] = 1.78936255;
	g[11] = -.15518801;
	g[12] = -.98360507;
	g[13] = .58322553;
	g[14] = -.9608422;
	g[15] = 1.02212226;
	g[16] = 3.58965909;
	g[17] = 2.13785201;
	g[18] = .10303835;
	g[19] = 4.04614941;
	g[20] = .05596182;
	g[21] = -.74156199;
	g[22] = 5.19929225;
	g[23] = 4.10382737;
	g[24] = 4.4548273;
	g[25] = 4.41742088;
	g[26] = .38736892;
	g[27] = .17670075;
	g[28] = 4.15725493;
	g[29] = -.22783536;
	g[30] = .58237005;
	g[31] = 3.04829469;
	g[32] = -1.;
	g[33] = -.28213036;
    }
    if (*i67 == 2) {
	g[1] = 1.07767821;
	g[2] = -.44761809;
	g[3] = .65368561;
	g[4] = -1.;
	g[5] = -.73027076;
	g[6] = -.96722505;
	g[7] = -.16648158;
	g[8] = -.9630052;
	g[9] = -.43043102;
	g[10] = -.33013524;
	g[11] = -.53458138;
	g[12] = .04519436;
	g[13] = .21059818;
	g[14] = 1.85997072;
	g[15] = 1.00887824;
	g[16] = .05296895;
	g[17] = -.75654657;
	g[18] = 3.99405505;
	g[19] = 2.10079382;
	g[20] = .71820448;
	g[21] = -.79308107;
	g[22] = .71794093;
	g[23] = 1.59649466;
	g[24] = -.42941671;
	g[25] = .05688063;
	g[26] = -.36715641;
	g[27] = .10866524;
	g[28] = -.40182486;
	g[29] = .87367028;
	g[30] = -.15730903;
	g[31] = 2.53653413;
	g[32] = -.2767428;
	g[33] = -.21904374;
    }
    return 0;
} /* io13_ */

/* Subroutine */ int io12_(integer *i67, doublereal *g)
{
    /* Parameter adjustments */
    --g;

    /* Function Body */
    if (*i67 == 1) {
	g[1] = 2.08181871;
	g[2] = .19941008;
	g[3] = .663559;
	g[4] = .2297929;
	g[5] = .45194597;
	g[6] = -.73231382;
	g[7] = 1.12731735;
	g[8] = .15438953;
	g[9] = .92589979;
	g[10] = .66252956;
	g[11] = 1.51928446;
	g[12] = -.42972569;
	g[13] = 1.67373601;
	g[14] = 1.88837352;
	g[15] = -.21119113;
	g[16] = .02374419;
	g[17] = .45582854;
	g[18] = -.27602405;
	g[19] = -.53242829;
	g[20] = .14369251;
	g[21] = -.00105148;
	g[22] = -.77738419;
	g[23] = -.53794328;
	g[24] = -.55895883;
	g[25] = .28001733;
	g[26] = -.11034496;
	g[27] = -.40392603;
	g[28] = .29138653;
	g[29] = .2377215;
	g[30] = .20211495;
	g[31] = .138778;
	g[32] = .65156465;
	g[33] = -.99249717;
    }
    if (*i67 == 2) {
	g[1] = -.4312276;
	g[2] = -.15189541;
	g[3] = .03960097;
	g[4] = -.33023865;
	g[5] = .37549423;
	g[6] = .46619011;
	g[7] = .01955984;
	g[8] = -.61703271;
	g[9] = -.10107408;
	g[10] = .0082648;
	g[11] = -.03994651;
	g[12] = -.21620967;
	g[13] = .12164474;
	g[14] = .12107576;
	g[15] = .18700566;
	g[16] = -.56889807;
	g[17] = .00153063;
	g[18] = -.07262216;
	g[19] = .80049358;
	g[20] = -.20426258;
	g[21] = .32111134;
	g[22] = .20215425;
	g[23] = .25647943;
	g[24] = .1400869;
	g[25] = .16738659;
	g[26] = 1.03552112;
	g[27] = .19846093;
	g[28] = -.06430121;
	g[29] = .12672987;
	g[30] = -.33030999;
	g[31] = .15749225;
	g[32] = -.05867185;
	g[33] = .59177165;
    }
    return 0;
} /* io12_ */

integer i301_(doublereal *a, doublereal *b)
{
    /* System generated locals */
    integer ret_val;

    ret_val = 0;
    if (*a < *b) {
	return ret_val;
    }
    if (*a > *b) {
	return ret_val;
    }
    ret_val = 1;
    return ret_val;
} /* i301_ */

integer i304_(doublereal *g)
{
    /* System generated locals */
    integer ret_val;

    ret_val = 0;
    if (*g != *g) {
	ret_val = 1;
    }
    return ret_val;
} /* i304_ */

doublereal i305_(void)
{
    /* Initialized data */

    static integer k27 = 1;
    static doublereal k26 = 1.;

    /* System generated locals */
    doublereal ret_val, d__1;

    /* Builtin functions */
    double pow_dd(doublereal *, doublereal *);

    /* Local variables */
    static integer i__;
    static doublereal i44, k25;
    static integer k28;

    if (k27 == 1) {
	k27 = 0;
	i44 = 0.;
	k28 = 0;
	for (i__ = 1; i__ <= 99; ++i__) {
	    i44 = k26;
	    k26 *= 10.;
	    ++k28;
	    if (i44 >= k26) {
		goto L1;
	    }
	}
L1:
	k25 = (doublereal) (k28 - 1);
	k26 = (d__1 = pow_dd(&c_b27, &k25), abs(d__1));
	if (k26 < 1e16) {
	    k26 = 1e16;
	}
    }
    ret_val = k26;
    return ret_val;
} /* i305_ */

/* Subroutine */ int io7_(doublereal *l, doublereal *x, integer *o, integer *
	n)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__;
    static doublereal k26;
    extern integer i304_(doublereal *);
    extern doublereal i305_(void);

    /* Parameter adjustments */
    --x;
    --l;

    /* Function Body */
    k26 = i305_();
    i__1 = *o;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (i304_(&l[i__]) == 1) {
	    l[i__] = k26;
	}
	if (l[i__] > k26) {
	    l[i__] = k26;
	}
    }
    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (i304_(&x[i__]) == 1) {
	    x[i__] = -k26;
	}
	if (x[i__] < -k26) {
	    x[i__] = -k26;
	}
    }
    return 0;
} /* io7_ */

/* Subroutine */ int io7_lomfy__(doublereal *l, integer *o)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__;
    static doublereal k26;
    extern integer i304_(doublereal *);
    extern doublereal i305_(void);

    /* Parameter adjustments */
    --l;

    /* Function Body */
    k26 = i305_();
    i__1 = *o;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (i304_(&l[i__]) == 1) {
	    l[i__] = k26;
	}
	if (l[i__] > k26) {
	    l[i__] = k26;
	}
    }
    return 0;
} /* io7_lomfy__ */

doublereal rio5_(doublereal *a, doublereal *b)
{
    /* System generated locals */
    doublereal ret_val, d__1, d__2;

    /* Local variables */
    static doublereal maxab;

/* Computing MAX */
    d__1 = abs(*a), d__2 = abs(*b);
    maxab = max(d__1,d__2);
    ret_val = (d__1 = *a - *b, abs(d__1));
    ret_val /= max(1.,maxab);
    return ret_val;
} /* rio5_ */

/* Subroutine */ int o18_(integer *i67s, char *i15, ftnlen i15_len)
{
    extern /* Subroutine */ int alphabet_(char *, integer *, ftnlen);
    static integer i__;

    /* Parameter adjustments */
    --i67s;

    /* Function Body */
    for (i__ = 1; i__ <= 60; ++i__) {
	alphabet_(i15 + (i__ - 1), &i67s[i__], (ftnlen)1);
    }
    return 0;
} /* o18_ */

/* end                       ol code */
/* Subroutine */ int alphabet_(char *a, integer *b, ftnlen a_len)
{
    *b = 0;
    if (*(unsigned char *)a == 'A') {
	*b = 52;
    }
    if (*(unsigned char *)a == 'B') {
	*b = 28;
    }
    if (*(unsigned char *)a == 'C') {
	*b = 49;
    }
    if (*(unsigned char *)a == 'D') {
	*b = 30;
    }
    if (*(unsigned char *)a == 'E') {
	*b = 31;
    }
    if (*(unsigned char *)a == 'F') {
	*b = 32;
    }
    if (*(unsigned char *)a == 'G') {
	*b = 33;
    }
    if (*(unsigned char *)a == 'H') {
	*b = 34;
    }
    if (*(unsigned char *)a == 'I') {
	*b = 35;
    }
    if (*(unsigned char *)a == 'J') {
	*b = 36;
    }
    if (*(unsigned char *)a == 'K') {
	*b = 37;
    }
    if (*(unsigned char *)a == 'L') {
	*b = 38;
    }
    if (*(unsigned char *)a == 'M') {
	*b = 39;
    }
    if (*(unsigned char *)a == 'N') {
	*b = 40;
    }
    if (*(unsigned char *)a == 'O') {
	*b = 41;
    }
    if (*(unsigned char *)a == 'P') {
	*b = 42;
    }
    if (*(unsigned char *)a == 'Q') {
	*b = 43;
    }
    if (*(unsigned char *)a == 'R') {
	*b = 44;
    }
    if (*(unsigned char *)a == 'S') {
	*b = 45;
    }
    if (*(unsigned char *)a == 'T') {
	*b = 46;
    }
    if (*(unsigned char *)a == 'U') {
	*b = 47;
    }
    if (*(unsigned char *)a == 'V') {
	*b = 48;
    }
    if (*(unsigned char *)a == 'W') {
	*b = 29;
    }
    if (*(unsigned char *)a == 'X') {
	*b = 50;
    }
    if (*(unsigned char *)a == 'Y') {
	*b = 51;
    }
    if (*(unsigned char *)a == 'Z') {
	*b = 27;
    }
    if (*(unsigned char *)a == '0') {
	*b = 53;
    }
    if (*(unsigned char *)a == '1') {
	*b = 54;
    }
    if (*(unsigned char *)a == '2') {
	*b = 55;
    }
    if (*(unsigned char *)a == '3') {
	*b = 56;
    }
    if (*(unsigned char *)a == '4') {
	*b = 57;
    }
    if (*(unsigned char *)a == '5') {
	*b = 58;
    }
    if (*(unsigned char *)a == '6') {
	*b = 59;
    }
    if (*(unsigned char *)a == '7') {
	*b = 60;
    }
    if (*(unsigned char *)a == '8') {
	*b = 61;
    }
    if (*(unsigned char *)a == '9') {
	*b = 62;
    }
    if (*(unsigned char *)a == 'a') {
	*b = 23;
    }
    if (*(unsigned char *)a == 'b') {
	*b = 2;
    }
    if (*(unsigned char *)a == 'c') {
	*b = 3;
    }
    if (*(unsigned char *)a == 'd') {
	*b = 16;
    }
    if (*(unsigned char *)a == 'e') {
	*b = 5;
    }
    if (*(unsigned char *)a == 'f') {
	*b = 13;
    }
    if (*(unsigned char *)a == 'g') {
	*b = 7;
    }
    if (*(unsigned char *)a == 'h') {
	*b = 8;
    }
    if (*(unsigned char *)a == 'i') {
	*b = 9;
    }
    if (*(unsigned char *)a == 'j') {
	*b = 10;
    }
    if (*(unsigned char *)a == 'k') {
	*b = 11;
    }
    if (*(unsigned char *)a == 'l') {
	*b = 12;
    }
    if (*(unsigned char *)a == 'm') {
	*b = 6;
    }
    if (*(unsigned char *)a == 'n') {
	*b = 14;
    }
    if (*(unsigned char *)a == 'o') {
	*b = 15;
    }
    if (*(unsigned char *)a == 'p') {
	*b = 4;
    }
    if (*(unsigned char *)a == 'q') {
	*b = 17;
    }
    if (*(unsigned char *)a == 'r') {
	*b = 18;
    }
    if (*(unsigned char *)a == 's') {
	*b = 19;
    }
    if (*(unsigned char *)a == 't') {
	*b = 20;
    }
    if (*(unsigned char *)a == 'u') {
	*b = 21;
    }
    if (*(unsigned char *)a == 'v') {
	*b = 22;
    }
    if (*(unsigned char *)a == 'w') {
	*b = 1;
    }
    if (*(unsigned char *)a == 'x') {
	*b = 24;
    }
    if (*(unsigned char *)a == 'y') {
	*b = 25;
    }
    if (*(unsigned char *)a == 'z') {
	*b = 26;
    }
    if (*(unsigned char *)a == '_') {
	*b = 64;
    }
    if (*(unsigned char *)a == '(') {
	*b = 65;
    }
    if (*(unsigned char *)a == ')') {
	*b = 66;
    }
    if (*(unsigned char *)a == '+') {
	*b = 67;
    }
    if (*(unsigned char *)a == '-') {
	*b = 68;
    }
    if (*(unsigned char *)a == '&') {
	*b = 69;
    }
    if (*(unsigned char *)a == '.') {
	*b = 70;
    }
    if (*(unsigned char *)a == ',') {
	*b = 71;
    }
    if (*(unsigned char *)a == ':') {
	*b = 72;
    }
    if (*(unsigned char *)a == ';') {
	*b = 73;
    }
    if (*(unsigned char *)a == '*') {
	*b = 74;
    }
    if (*(unsigned char *)a == '=') {
	*b = 75;
    }
    if (*(unsigned char *)a == '/') {
	*b = 76;
    }
    if (*(unsigned char *)a == '!') {
	*b = 80;
    }
    if (*(unsigned char *)a == '[') {
	*b = 83;
    }
    if (*(unsigned char *)a == ']') {
	*b = 84;
    }
    return 0;
} /* alphabet_ */

/* This is the MIDACO.c f2c-header from below */

#ifdef KR_headers
double pow();
double pow_dd(ap, bp) doublereal *ap, *bp;
#else
#undef abs
#include "math.h"
#ifdef __cplusplus
extern "C" {
#endif
double pow_dd(doublereal *ap, doublereal *bp)
#endif
{
return(pow(*ap, *bp) );
}
#ifdef __cplusplus
}
#endif
double d_nint(x)
doublereal *x;
{
double floor();

return( (*x)>=0 ?
 floor(*x + .5) : -floor(.5 - *x) );
}
#ifdef __cplusplus
extern "C" {
#endif
#ifdef KR_headers
double pow_di(ap, bp) doublereal *ap; integer *bp;
#else
double pow_di(doublereal *ap, integer *bp)
#endif
{
double pow, x;
integer n;
unsigned long u;
pow = 1;
x = *ap;
n = *bp;
if(n != 0)
 {
 if(n < 0)
  {
  n = -n;
  x = 1/x;
  }
 for(u = n; ; )
  {
  if(u & 01)
   pow *= x;
  if(u >>= 1)
   x *= x;
  else
   break;
  }
 }
return(pow);
}
#ifdef __cplusplus
}
#endif
#ifdef __cplusplus
extern "C" {
#endif
#ifdef KR_headers
integer pow_ii(ap, bp) integer *ap, *bp;
#else
integer pow_ii(integer *ap, integer *bp)
#endif
{
 integer pow, x, n;
 unsigned long u;
 x = *ap;
 n = *bp;
 if (n <= 0) {
  if (n == 0 || x == 1)
   return 1;
  if (x != -1)
   return x == 0 ? 1/x : 0;
  n = -n;
  }
 u = n;
 for(pow = 1; ; )
  {
  if(u & 01)
   pow *= x;
  if(u >>= 1)
   x *= x;
  else
   break;
  }
 return(pow);
 }
#ifdef __cplusplus
}
#endif
#ifdef KR_headers
double floor();
integer i_dnnt(x) doublereal *x;
#else
#undef abs
#include "math.h"
#ifdef __cplusplus
extern "C" {
#endif
integer i_dnnt(doublereal *x)
#endif
{
return (integer)(*x >= 0. ? floor(*x + .5) : -floor(.5 - *x));
}
#ifdef __cplusplus
}
#endif
