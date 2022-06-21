/* --- UPCR system headers --- */ 
#include "upcr.h" 
#include "whirl2c.h"
#include "upcr_proxy.h"
/*******************************************************
 * C file translated from WHIRL Tue Jun 21 03:32:23 2022
 *******************************************************/

/* UPC Runtime specification expected: 3.6 */
#define UPCR_WANT_MAJOR 3
#define UPCR_WANT_MINOR 6
/* UPC translator version: release 2.28.2, built on Dec 11 2020 at 14:19:36, host aphid.lbl.gov linux-x86_64/64, gcc v9.3.0 */
/* Included code from the initialization script */
#include</home/marcin/Dokumenty/upc/opt/upcr_config.h>
#include</home/marcin/Dokumenty/upc/gasnet/other/gasnet_portable_platform.h>
#include</home/marcin/Dokumenty/upc/upcr_preinclude/upc_types.h>
#include "upcr_geninclude/stddef.h"
#include</home/marcin/Dokumenty/upc/upcr_preinclude/upc_bits.h>
#include "upcr_geninclude/stdlib.h"
#include "upcr_geninclude/inttypes.h"
#include "upcr_geninclude/stdio.h"
#include "upcr_geninclude/math.h"
#line 1 "main.w2c.h"
/* Include builtin types and operators */

#ifndef UPCR_TRANS_EXTRA_INCL
#define UPCR_TRANS_EXTRA_INCL
extern int upcrt_gcd (int _a, int _b);
extern int _upcrt_forall_start(int _start_thread, int _step, int _lo, int _scale);
#define upcrt_forall_start(start_thread, step, lo, scale)  \
       _upcrt_forall_start(start_thread, step, lo, scale)
int32_t UPCR_TLD_DEFINE_TENTATIVE(upcrt_forall_control, 4, 4);
#define upcr_forall_control upcrt_forall_control
#ifndef UPCR_EXIT_FUNCTION
#define UPCR_EXIT_FUNCTION() ((void)0)
#endif
#if UPCR_RUNTIME_SPEC_MAJOR > 3 || (UPCR_RUNTIME_SPEC_MAJOR == 3 && UPCR_RUNTIME_SPEC_MINOR >= 8)
  #define UPCRT_STARTUP_SHALLOC(sptr, blockbytes, numblocks, mult_by_threads, elemsz, typestr) \
      { &(sptr), (blockbytes), (numblocks), (mult_by_threads), (elemsz), #sptr, (typestr) }
#else
  #define UPCRT_STARTUP_SHALLOC(sptr, blockbytes, numblocks, mult_by_threads, elemsz, typestr) \
      { &(sptr), (blockbytes), (numblocks), (mult_by_threads) }
#endif
#define UPCRT_STARTUP_PSHALLOC UPCRT_STARTUP_SHALLOC

/**** Autonb optimization ********/

extern void _upcrt_memput_nb(upcr_shared_ptr_t _dst, const void *_src, size_t _n);
#define upcrt_memput_nb(dst, src, n) \
       (upcri_srcpos(), _upcrt_memput_nb(dst, src, n))

#endif


/* Types */
/* File-level vars and routines */
extern int user_main();

extern void print_data(const char *);

extern void fft();

extern void dft_reverse();

extern void dft();

extern void bit_reversal_copy();

extern void fft_reverse();

extern int bit_reverse(int);


#define UPCR_SHARED_SIZE_ 8
#define UPCR_PSHARED_SIZE_ 8
upcr_pshared_ptr_t data;
upcr_pshared_ptr_t data_cpy;

void UPCRI_ALLOC_main_6953773828161(void) { 
UPCR_BEGIN_FUNCTION();
upcr_startup_pshalloc_t _bupc_pinfo[] = { 
UPCRT_STARTUP_PSHALLOC(data, 8, 16, 1, 8, "A16H_R1_d"), 
UPCRT_STARTUP_PSHALLOC(data_cpy, 8, 16, 1, 8, "A16H_R1_d"), 
 };

UPCR_SET_SRCPOS("_main_6953773828161_ALLOC",0);
upcr_startup_pshalloc(_bupc_pinfo, sizeof(_bupc_pinfo) / sizeof(upcr_startup_pshalloc_t));
}

void UPCRI_INIT_main_6953773828161(void) { 
UPCR_BEGIN_FUNCTION();
UPCR_SET_SRCPOS("_main_6953773828161_INIT",0);
}

#line 27 "./src/main.c"
extern int user_main()
#line 27 "./src/main.c"
{
#line 27 "./src/main.c"
  UPCR_BEGIN_FUNCTION();
  register _IEEE64 _bupc_comma;
  register _INT32 _bupc_comma0;
  int i;
  _INT32 _bupc_Tthreads0;
  upcr_pshared_ptr_t _bupc_Mptra0;
  upcr_pshared_ptr_t _bupc_Mptra1;
  _IEEE64 _bupc_spillstoreparm2;
  upcr_pshared_ptr_t _bupc_Mptra3;
  upcr_pshared_ptr_t _bupc_Mptra4;
  _IEEE64 _bupc_spillstoreparm5;
  
#line 29 "./src/main.c"
  if((*((_INT32 *) UPCR_TLD_ADDR( upcr_forall_control ))))
#line 29 "./src/main.c"
  {
#line 29 "./src/main.c"
    i = 0;
#line 29 "./src/main.c"
    while(i < (((int) upcr_threads () ) * 8))
    {
#line 31 "./src/main.c"
      _bupc_comma = sin((_IEEE64)(i) * 0.2);
#line 31 "./src/main.c"
      _bupc_Mptra0 = UPCR_ADD_PSHARED1(data, 8ULL, i);
      UPCR_PUT_PSHARED_DOUBLEVAL(_bupc_Mptra0, 0, _bupc_comma);
#line 32 "./src/main.c"
      _bupc_Mptra1 = UPCR_ADD_PSHARED1(data, 8ULL, i + (((int) upcr_threads () ) * 8));
      _bupc_spillstoreparm2 = 0.0;
#line 32 "./src/main.c"
      UPCR_PUT_PSHARED(_bupc_Mptra1, 0, &_bupc_spillstoreparm2, 8);
#line 33 "./src/main.c"
      _8 :;
#line 33 "./src/main.c"
      i = i + 1;
    }
  }
  else
#line 29 "./src/main.c"
  {
#line 29 "./src/main.c"
    (*((_INT32 *) UPCR_TLD_ADDR( upcr_forall_control ))) = 1;
#line 29 "./src/main.c"
    i = 0;
#line 29 "./src/main.c"
    while(i < (((int) upcr_threads () ) * 8))
#line 29 "./src/main.c"
    {
      _bupc_Tthreads0 = upcr_threads();
      _bupc_comma0 = upcr_mythread();
      if((i % _bupc_Tthreads0) == _bupc_comma0)
      {
#line 31 "./src/main.c"
        _bupc_comma = sin((_IEEE64)(i) * 0.2);
#line 31 "./src/main.c"
        _bupc_Mptra3 = UPCR_ADD_PSHARED1(data, 8ULL, i);
        UPCR_PUT_PSHARED_DOUBLEVAL(_bupc_Mptra3, 0, _bupc_comma);
#line 32 "./src/main.c"
        _bupc_Mptra4 = UPCR_ADD_PSHARED1(data, 8ULL, i + (((int) upcr_threads () ) * 8));
        _bupc_spillstoreparm5 = 0.0;
#line 32 "./src/main.c"
        UPCR_PUT_PSHARED(_bupc_Mptra4, 0, &_bupc_spillstoreparm5, 8);
      }
#line 33 "./src/main.c"
      _1 :;
#line 33 "./src/main.c"
      i = i + 1;
    }
#line 29 "./src/main.c"
    (*((_INT32 *) UPCR_TLD_ADDR( upcr_forall_control ))) = 0;
  }
#line 34 "./src/main.c"
  upcr_barrier(221775937, 1);
#line 35 "./src/main.c"
  print_data("data/in_fft.csv");
#line 38 "./src/main.c"
  fft();
#line 39 "./src/main.c"
  print_data("data/out_fft.csv");
#line 42 "./src/main.c"
  dft_reverse();
#line 43 "./src/main.c"
  print_data("data/out_ifft.csv");
#line 46 "./src/main.c"
  upcr_barrier(221775938, 1);
#line 47 "./src/main.c"
  if(((int) upcr_mythread () ) == 0)
#line 47 "./src/main.c"
  {
#line 49 "./src/main.c"
    printf("Application executed successfully.\n");
  }
#line 51 "./src/main.c"
  UPCR_EXIT_FUNCTION();
#line 51 "./src/main.c"
  return 0;
} /* user_main */


#line 57 "./src/main.c"
extern void dft()
#line 57 "./src/main.c"
{
#line 57 "./src/main.c"
  UPCR_BEGIN_FUNCTION();
  register _INT32 _bupc_comma;
  register _IEEE64 _bupc_comma0;
  register _IEEE64 _bupc_comma1;
  register _IEEE64 _bupc_comma2;
  register _IEEE64 _bupc_comma3;
  register _INT32 _bupc_comma4;
  register _INT32 _bupc_comma5;
  int k;
  _INT32 _bupc_Tthreads1;
  int _bupc_w2c_k0;
  _INT32 _bupc_Tthreads2;
  _IEEE64 c[2LL];
  int n;
  _IEEE64 arg;
  int _bupc_w2c_k1;
  _INT32 _bupc_Tthreads3;
  upcr_pshared_ptr_t _bupc_Mptra6;
  _IEEE64 _bupc_spillstoreparm7;
  upcr_pshared_ptr_t _bupc_Mptra8;
  _IEEE64 _bupc_spillstoreparm9;
  upcr_pshared_ptr_t _bupc_Mptra10;
  _IEEE64 _bupc_spillstoreparm11;
  upcr_pshared_ptr_t _bupc_Mptra12;
  _IEEE64 _bupc_spillstoreparm13;
  upcr_pshared_ptr_t _bupc_Mptra14;
  _IEEE64 _bupc_spillld15;
  upcr_pshared_ptr_t _bupc_Mptra16;
  _IEEE64 _bupc_spillld17;
  upcr_pshared_ptr_t _bupc_Mptra18;
  _IEEE64 _bupc_spillld19;
  upcr_pshared_ptr_t _bupc_Mptra20;
  _IEEE64 _bupc_spillld21;
  upcr_pshared_ptr_t _bupc_Mptra22;
  _IEEE64 _bupc_spillstoreparm23;
  upcr_pshared_ptr_t _bupc_Mptra24;
  _IEEE64 _bupc_spillstoreparm25;
  upcr_pshared_ptr_t _bupc_Mptra26;
  _IEEE64 _bupc_spillld27;
  upcr_pshared_ptr_t _bupc_Mptra28;
  _IEEE64 _bupc_spillld29;
  upcr_pshared_ptr_t _bupc_Mptra30;
  _IEEE64 _bupc_spillld31;
  upcr_pshared_ptr_t _bupc_Mptra32;
  _IEEE64 _bupc_spillld33;
  upcr_pshared_ptr_t _bupc_Mptra34;
  _IEEE64 _bupc_spillstoreparm35;
  upcr_pshared_ptr_t _bupc_Mptra36;
  _IEEE64 _bupc_spillstoreparm37;
  upcr_pshared_ptr_t _bupc_Mptra38;
  _IEEE64 _bupc_spillld39;
  upcr_pshared_ptr_t _bupc_Mptra40;
  upcr_pshared_ptr_t _bupc_Mptra41;
  _IEEE64 _bupc_spillld42;
  upcr_pshared_ptr_t _bupc_Mptra43;
  upcr_pshared_ptr_t _bupc_Mptra44;
  _IEEE64 _bupc_spillld45;
  upcr_pshared_ptr_t _bupc_Mptra46;
  upcr_pshared_ptr_t _bupc_Mptra47;
  _IEEE64 _bupc_spillld48;
  upcr_pshared_ptr_t _bupc_Mptra49;
  
#line 58 "./src/main.c"
  if((*((_INT32 *) UPCR_TLD_ADDR( upcr_forall_control ))))
#line 58 "./src/main.c"
  {
#line 58 "./src/main.c"
    k = 0;
#line 58 "./src/main.c"
    while(k < (((int) upcr_threads () ) * 8))
    {
#line 60 "./src/main.c"
      _bupc_Mptra6 = UPCR_ADD_PSHARED1(data_cpy, 8ULL, k);
      _bupc_spillstoreparm7 = 0.0;
#line 60 "./src/main.c"
      UPCR_PUT_PSHARED(_bupc_Mptra6, 0, &_bupc_spillstoreparm7, 8);
#line 61 "./src/main.c"
      _bupc_Mptra8 = UPCR_ADD_PSHARED1(data_cpy, 8ULL, k + (((int) upcr_threads () ) * 8));
      _bupc_spillstoreparm9 = 0.0;
#line 61 "./src/main.c"
      UPCR_PUT_PSHARED(_bupc_Mptra8, 0, &_bupc_spillstoreparm9, 8);
#line 62 "./src/main.c"
      _19 :;
#line 62 "./src/main.c"
      k = k + 1;
    }
  }
  else
#line 58 "./src/main.c"
  {
#line 58 "./src/main.c"
    (*((_INT32 *) UPCR_TLD_ADDR( upcr_forall_control ))) = 1;
#line 58 "./src/main.c"
    k = 0;
#line 58 "./src/main.c"
    while(k < (((int) upcr_threads () ) * 8))
#line 58 "./src/main.c"
    {
      _bupc_Tthreads1 = upcr_threads();
      _bupc_comma = upcr_mythread();
      if((k % _bupc_Tthreads1) == _bupc_comma)
      {
#line 60 "./src/main.c"
        _bupc_Mptra10 = UPCR_ADD_PSHARED1(data_cpy, 8ULL, k);
        _bupc_spillstoreparm11 = 0.0;
#line 60 "./src/main.c"
        UPCR_PUT_PSHARED(_bupc_Mptra10, 0, &_bupc_spillstoreparm11, 8);
#line 61 "./src/main.c"
        _bupc_Mptra12 = UPCR_ADD_PSHARED1(data_cpy, 8ULL, k + (((int) upcr_threads () ) * 8));
        _bupc_spillstoreparm13 = 0.0;
#line 61 "./src/main.c"
        UPCR_PUT_PSHARED(_bupc_Mptra12, 0, &_bupc_spillstoreparm13, 8);
      }
#line 62 "./src/main.c"
      _1 :;
#line 62 "./src/main.c"
      k = k + 1;
    }
#line 58 "./src/main.c"
    (*((_INT32 *) UPCR_TLD_ADDR( upcr_forall_control ))) = 0;
  }
#line 63 "./src/main.c"
  upcr_barrier(221775939, 1);
#line 67 "./src/main.c"
  if((*((_INT32 *) UPCR_TLD_ADDR( upcr_forall_control ))))
#line 67 "./src/main.c"
  {
#line 67 "./src/main.c"
    _bupc_w2c_k0 = 0;
#line 67 "./src/main.c"
    while(_bupc_w2c_k0 < (((int) upcr_threads () ) * 8))
    {
#line 69 "./src/main.c"
      (c)[0] = 0.0;
#line 70 "./src/main.c"
      (c)[1] = 0.0;
#line 71 "./src/main.c"
      n = 0;
#line 71 "./src/main.c"
      while(n < (((int) upcr_threads () ) * 8))
#line 71 "./src/main.c"
      {
#line 73 "./src/main.c"
        arg = (((_IEEE64)(_bupc_w2c_k0) * -6.283) * (_IEEE64)(n)) / (_IEEE64)((((int) upcr_threads () ) * 8));
#line 74 "./src/main.c"
        _bupc_comma0 = cos(arg);
#line 74 "./src/main.c"
        _bupc_comma1 = sin(arg);
#line 74 "./src/main.c"
        _bupc_Mptra14 = UPCR_ADD_PSHARED1(data, 8ULL, n);
#line 74 "./src/main.c"
        _bupc_spillld15 = UPCR_GET_PSHARED_DOUBLEVAL(_bupc_Mptra14, 0);
#line 74 "./src/main.c"
        _bupc_Mptra16 = UPCR_ADD_PSHARED1(data, 8ULL, n + (((int) upcr_threads () ) * 8));
#line 74 "./src/main.c"
        _bupc_spillld17 = UPCR_GET_PSHARED_DOUBLEVAL(_bupc_Mptra16, 0);
#line 74 "./src/main.c"
        (c)[0] = (c)[0] + ((_bupc_spillld15 * _bupc_comma0) - (_bupc_spillld17 * _bupc_comma1));
#line 75 "./src/main.c"
        _bupc_comma2 = cos(arg);
#line 75 "./src/main.c"
        _bupc_comma3 = sin(arg);
#line 75 "./src/main.c"
        _bupc_Mptra18 = UPCR_ADD_PSHARED1(data, 8ULL, n + (((int) upcr_threads () ) * 8));
#line 75 "./src/main.c"
        _bupc_spillld19 = UPCR_GET_PSHARED_DOUBLEVAL(_bupc_Mptra18, 0);
#line 75 "./src/main.c"
        _bupc_Mptra20 = UPCR_ADD_PSHARED1(data, 8ULL, n);
#line 75 "./src/main.c"
        _bupc_spillld21 = UPCR_GET_PSHARED_DOUBLEVAL(_bupc_Mptra20, 0);
#line 75 "./src/main.c"
        (c)[1] = (c)[1] + ((_bupc_spillld19 * _bupc_comma2) + (_bupc_spillld21 * _bupc_comma3));
#line 76 "./src/main.c"
        _20 :;
#line 76 "./src/main.c"
        n = n + 1;
      }
#line 77 "./src/main.c"
      _bupc_Mptra22 = UPCR_ADD_PSHARED1(data_cpy, 8ULL, _bupc_w2c_k0);
      _bupc_spillstoreparm23 = (c)[0];
#line 77 "./src/main.c"
      UPCR_PUT_PSHARED(_bupc_Mptra22, 0, &_bupc_spillstoreparm23, 8);
#line 78 "./src/main.c"
      _bupc_Mptra24 = UPCR_ADD_PSHARED1(data_cpy, 8ULL, _bupc_w2c_k0 + (((int) upcr_threads () ) * 8));
      _bupc_spillstoreparm25 = (c)[1];
#line 78 "./src/main.c"
      UPCR_PUT_PSHARED(_bupc_Mptra24, 0, &_bupc_spillstoreparm25, 8);
#line 79 "./src/main.c"
      upcr_barrier(221775940, 1);
#line 80 "./src/main.c"
      _21 :;
#line 80 "./src/main.c"
      _bupc_w2c_k0 = _bupc_w2c_k0 + 1;
    }
  }
  else
#line 67 "./src/main.c"
  {
#line 67 "./src/main.c"
    (*((_INT32 *) UPCR_TLD_ADDR( upcr_forall_control ))) = 1;
#line 67 "./src/main.c"
    _bupc_w2c_k0 = 0;
#line 67 "./src/main.c"
    while(_bupc_w2c_k0 < (((int) upcr_threads () ) * 8))
#line 67 "./src/main.c"
    {
      _bupc_Tthreads2 = upcr_threads();
      _bupc_comma4 = upcr_mythread();
      if((_bupc_w2c_k0 % _bupc_Tthreads2) == _bupc_comma4)
      {
#line 69 "./src/main.c"
        (c)[0] = 0.0;
#line 70 "./src/main.c"
        (c)[1] = 0.0;
#line 71 "./src/main.c"
        n = 0;
#line 71 "./src/main.c"
        while(n < (((int) upcr_threads () ) * 8))
#line 71 "./src/main.c"
        {
#line 73 "./src/main.c"
          arg = (((_IEEE64)(_bupc_w2c_k0) * -6.283) * (_IEEE64)(n)) / (_IEEE64)((((int) upcr_threads () ) * 8));
#line 74 "./src/main.c"
          _bupc_comma0 = cos(arg);
#line 74 "./src/main.c"
          _bupc_comma1 = sin(arg);
#line 74 "./src/main.c"
          _bupc_Mptra26 = UPCR_ADD_PSHARED1(data, 8ULL, n);
#line 74 "./src/main.c"
          _bupc_spillld27 = UPCR_GET_PSHARED_DOUBLEVAL(_bupc_Mptra26, 0);
#line 74 "./src/main.c"
          _bupc_Mptra28 = UPCR_ADD_PSHARED1(data, 8ULL, n + (((int) upcr_threads () ) * 8));
#line 74 "./src/main.c"
          _bupc_spillld29 = UPCR_GET_PSHARED_DOUBLEVAL(_bupc_Mptra28, 0);
#line 74 "./src/main.c"
          (c)[0] = (c)[0] + ((_bupc_spillld27 * _bupc_comma0) - (_bupc_spillld29 * _bupc_comma1));
#line 75 "./src/main.c"
          _bupc_comma2 = cos(arg);
#line 75 "./src/main.c"
          _bupc_comma3 = sin(arg);
#line 75 "./src/main.c"
          _bupc_Mptra30 = UPCR_ADD_PSHARED1(data, 8ULL, n + (((int) upcr_threads () ) * 8));
#line 75 "./src/main.c"
          _bupc_spillld31 = UPCR_GET_PSHARED_DOUBLEVAL(_bupc_Mptra30, 0);
#line 75 "./src/main.c"
          _bupc_Mptra32 = UPCR_ADD_PSHARED1(data, 8ULL, n);
#line 75 "./src/main.c"
          _bupc_spillld33 = UPCR_GET_PSHARED_DOUBLEVAL(_bupc_Mptra32, 0);
#line 75 "./src/main.c"
          (c)[1] = (c)[1] + ((_bupc_spillld31 * _bupc_comma2) + (_bupc_spillld33 * _bupc_comma3));
#line 76 "./src/main.c"
          _3 :;
#line 76 "./src/main.c"
          n = n + 1;
        }
#line 77 "./src/main.c"
        _bupc_Mptra34 = UPCR_ADD_PSHARED1(data_cpy, 8ULL, _bupc_w2c_k0);
        _bupc_spillstoreparm35 = (c)[0];
#line 77 "./src/main.c"
        UPCR_PUT_PSHARED(_bupc_Mptra34, 0, &_bupc_spillstoreparm35, 8);
#line 78 "./src/main.c"
        _bupc_Mptra36 = UPCR_ADD_PSHARED1(data_cpy, 8ULL, _bupc_w2c_k0 + (((int) upcr_threads () ) * 8));
        _bupc_spillstoreparm37 = (c)[1];
#line 78 "./src/main.c"
        UPCR_PUT_PSHARED(_bupc_Mptra36, 0, &_bupc_spillstoreparm37, 8);
#line 79 "./src/main.c"
        upcr_barrier(221775940, 1);
      }
#line 80 "./src/main.c"
      _2 :;
#line 80 "./src/main.c"
      _bupc_w2c_k0 = _bupc_w2c_k0 + 1;
    }
#line 67 "./src/main.c"
    (*((_INT32 *) UPCR_TLD_ADDR( upcr_forall_control ))) = 0;
  }
#line 81 "./src/main.c"
  if((*((_INT32 *) UPCR_TLD_ADDR( upcr_forall_control ))))
#line 81 "./src/main.c"
  {
#line 81 "./src/main.c"
    _bupc_w2c_k1 = 0;
#line 81 "./src/main.c"
    while(_bupc_w2c_k1 < (((int) upcr_threads () ) * 8))
    {
#line 83 "./src/main.c"
      _bupc_Mptra40 = UPCR_ADD_PSHARED1(data, 8ULL, _bupc_w2c_k1);
#line 83 "./src/main.c"
      _bupc_Mptra38 = UPCR_ADD_PSHARED1(data_cpy, 8ULL, _bupc_w2c_k1);
#line 83 "./src/main.c"
      _bupc_spillld39 = UPCR_GET_PSHARED_DOUBLEVAL(_bupc_Mptra38, 0);
#line 83 "./src/main.c"
      UPCR_PUT_PSHARED(_bupc_Mptra40, 0, &_bupc_spillld39, 8);
#line 84 "./src/main.c"
      _bupc_Mptra43 = UPCR_ADD_PSHARED1(data, 8ULL, _bupc_w2c_k1 + (((int) upcr_threads () ) * 8));
#line 84 "./src/main.c"
      _bupc_Mptra41 = UPCR_ADD_PSHARED1(data_cpy, 8ULL, _bupc_w2c_k1 + (((int) upcr_threads () ) * 8));
#line 84 "./src/main.c"
      _bupc_spillld42 = UPCR_GET_PSHARED_DOUBLEVAL(_bupc_Mptra41, 0);
#line 84 "./src/main.c"
      UPCR_PUT_PSHARED(_bupc_Mptra43, 0, &_bupc_spillld42, 8);
#line 85 "./src/main.c"
      _22 :;
#line 85 "./src/main.c"
      _bupc_w2c_k1 = _bupc_w2c_k1 + 1;
    }
  }
  else
#line 81 "./src/main.c"
  {
#line 81 "./src/main.c"
    (*((_INT32 *) UPCR_TLD_ADDR( upcr_forall_control ))) = 1;
#line 81 "./src/main.c"
    _bupc_w2c_k1 = 0;
#line 81 "./src/main.c"
    while(_bupc_w2c_k1 < (((int) upcr_threads () ) * 8))
#line 81 "./src/main.c"
    {
      _bupc_Tthreads3 = upcr_threads();
      _bupc_comma5 = upcr_mythread();
      if((_bupc_w2c_k1 % _bupc_Tthreads3) == _bupc_comma5)
      {
#line 83 "./src/main.c"
        _bupc_Mptra46 = UPCR_ADD_PSHARED1(data, 8ULL, _bupc_w2c_k1);
#line 83 "./src/main.c"
        _bupc_Mptra44 = UPCR_ADD_PSHARED1(data_cpy, 8ULL, _bupc_w2c_k1);
#line 83 "./src/main.c"
        _bupc_spillld45 = UPCR_GET_PSHARED_DOUBLEVAL(_bupc_Mptra44, 0);
#line 83 "./src/main.c"
        UPCR_PUT_PSHARED(_bupc_Mptra46, 0, &_bupc_spillld45, 8);
#line 84 "./src/main.c"
        _bupc_Mptra49 = UPCR_ADD_PSHARED1(data, 8ULL, _bupc_w2c_k1 + (((int) upcr_threads () ) * 8));
#line 84 "./src/main.c"
        _bupc_Mptra47 = UPCR_ADD_PSHARED1(data_cpy, 8ULL, _bupc_w2c_k1 + (((int) upcr_threads () ) * 8));
#line 84 "./src/main.c"
        _bupc_spillld48 = UPCR_GET_PSHARED_DOUBLEVAL(_bupc_Mptra47, 0);
#line 84 "./src/main.c"
        UPCR_PUT_PSHARED(_bupc_Mptra49, 0, &_bupc_spillld48, 8);
      }
#line 85 "./src/main.c"
      _4 :;
#line 85 "./src/main.c"
      _bupc_w2c_k1 = _bupc_w2c_k1 + 1;
    }
#line 81 "./src/main.c"
    (*((_INT32 *) UPCR_TLD_ADDR( upcr_forall_control ))) = 0;
  }
#line 86 "./src/main.c"
  upcr_barrier(221775941, 1);
  UPCR_EXIT_FUNCTION();
  return;
} /* dft */


#line 90 "./src/main.c"
extern void dft_reverse()
#line 90 "./src/main.c"
{
#line 90 "./src/main.c"
  UPCR_BEGIN_FUNCTION();
  register _INT32 _bupc_comma;
  register _INT32 _bupc_comma0;
  int i;
  _INT32 _bupc_Tthreads4;
  _INT32 _bupc_Tthreads5;
  upcr_pshared_ptr_t _bupc_Mptra50;
  _IEEE64 _bupc_spillld51;
  upcr_pshared_ptr_t _bupc_Mptra52;
  _IEEE64 _bupc_spillstoreparm53;
  upcr_pshared_ptr_t _bupc_Mptra54;
  _IEEE64 _bupc_spillld55;
  upcr_pshared_ptr_t _bupc_Mptra56;
  _IEEE64 _bupc_spillstoreparm57;
  upcr_pshared_ptr_t _bupc_Mptra58;
  _IEEE64 _bupc_spillld59;
  upcr_pshared_ptr_t _bupc_Mptra60;
  _IEEE64 _bupc_spillstoreparm61;
  upcr_pshared_ptr_t _bupc_Mptra62;
  _IEEE64 _bupc_spillld63;
  upcr_pshared_ptr_t _bupc_Mptra64;
  _IEEE64 _bupc_spillstoreparm65;
  upcr_pshared_ptr_t _bupc_Mptra66;
  _IEEE64 _bupc_spillld67;
  upcr_pshared_ptr_t _bupc_Mptra68;
  _IEEE64 _bupc_spillstoreparm69;
  upcr_pshared_ptr_t _bupc_Mptra70;
  _IEEE64 _bupc_spillld71;
  upcr_pshared_ptr_t _bupc_Mptra72;
  _IEEE64 _bupc_spillstoreparm73;
  
#line 92 "./src/main.c"
  if((*((_INT32 *) UPCR_TLD_ADDR( upcr_forall_control ))))
#line 92 "./src/main.c"
  {
#line 92 "./src/main.c"
    i = 0;
#line 92 "./src/main.c"
    while(i < (((int) upcr_threads () ) * 8))
    {
#line 94 "./src/main.c"
      _bupc_Mptra52 = UPCR_ADD_PSHARED1(data, 8ULL, i + (((int) upcr_threads () ) * 8));
#line 94 "./src/main.c"
      _bupc_Mptra50 = UPCR_ADD_PSHARED1(data, 8ULL, i + (((int) upcr_threads () ) * 8));
#line 94 "./src/main.c"
      _bupc_spillld51 = UPCR_GET_PSHARED_DOUBLEVAL(_bupc_Mptra50, 0);
      _bupc_spillstoreparm53 = -_bupc_spillld51;
#line 94 "./src/main.c"
      UPCR_PUT_PSHARED(_bupc_Mptra52, 0, &_bupc_spillstoreparm53, 8);
#line 95 "./src/main.c"
      _11 :;
#line 95 "./src/main.c"
      i = i + 1;
    }
  }
  else
#line 92 "./src/main.c"
  {
#line 92 "./src/main.c"
    (*((_INT32 *) UPCR_TLD_ADDR( upcr_forall_control ))) = 1;
#line 92 "./src/main.c"
    i = 0;
#line 92 "./src/main.c"
    while(i < (((int) upcr_threads () ) * 8))
#line 92 "./src/main.c"
    {
      _bupc_Tthreads4 = upcr_threads();
      _bupc_comma = upcr_mythread();
      if((i % _bupc_Tthreads4) == _bupc_comma)
      {
#line 94 "./src/main.c"
        _bupc_Mptra56 = UPCR_ADD_PSHARED1(data, 8ULL, i + (((int) upcr_threads () ) * 8));
#line 94 "./src/main.c"
        _bupc_Mptra54 = UPCR_ADD_PSHARED1(data, 8ULL, i + (((int) upcr_threads () ) * 8));
#line 94 "./src/main.c"
        _bupc_spillld55 = UPCR_GET_PSHARED_DOUBLEVAL(_bupc_Mptra54, 0);
        _bupc_spillstoreparm57 = -_bupc_spillld55;
#line 94 "./src/main.c"
        UPCR_PUT_PSHARED(_bupc_Mptra56, 0, &_bupc_spillstoreparm57, 8);
      }
#line 95 "./src/main.c"
      _1 :;
#line 95 "./src/main.c"
      i = i + 1;
    }
#line 92 "./src/main.c"
    (*((_INT32 *) UPCR_TLD_ADDR( upcr_forall_control ))) = 0;
  }
#line 96 "./src/main.c"
  upcr_barrier(221775942, 1);
#line 97 "./src/main.c"
  dft();
#line 98 "./src/main.c"
  if((*((_INT32 *) UPCR_TLD_ADDR( upcr_forall_control ))))
#line 98 "./src/main.c"
  {
#line 98 "./src/main.c"
    i = 0;
#line 98 "./src/main.c"
    while(i < (((int) upcr_threads () ) * 8))
    {
#line 100 "./src/main.c"
      _bupc_Mptra60 = UPCR_ADD_PSHARED1(data, 8ULL, i);
#line 100 "./src/main.c"
      _bupc_Mptra58 = UPCR_ADD_PSHARED1(data, 8ULL, i);
#line 100 "./src/main.c"
      _bupc_spillld59 = UPCR_GET_PSHARED_DOUBLEVAL(_bupc_Mptra58, 0);
      _bupc_spillstoreparm61 = _bupc_spillld59 / (_IEEE64)((((int) upcr_threads () ) * 8));
#line 100 "./src/main.c"
      UPCR_PUT_PSHARED(_bupc_Mptra60, 0, &_bupc_spillstoreparm61, 8);
#line 101 "./src/main.c"
      _bupc_Mptra64 = UPCR_ADD_PSHARED1(data, 8ULL, i + (((int) upcr_threads () ) * 8));
#line 101 "./src/main.c"
      _bupc_Mptra62 = UPCR_ADD_PSHARED1(data, 8ULL, i + (((int) upcr_threads () ) * 8));
#line 101 "./src/main.c"
      _bupc_spillld63 = UPCR_GET_PSHARED_DOUBLEVAL(_bupc_Mptra62, 0);
      _bupc_spillstoreparm65 = (-_bupc_spillld63) / (_IEEE64)((((int) upcr_threads () ) * 8));
#line 101 "./src/main.c"
      UPCR_PUT_PSHARED(_bupc_Mptra64, 0, &_bupc_spillstoreparm65, 8);
#line 102 "./src/main.c"
      _12 :;
#line 102 "./src/main.c"
      i = i + 1;
    }
  }
  else
#line 98 "./src/main.c"
  {
#line 98 "./src/main.c"
    (*((_INT32 *) UPCR_TLD_ADDR( upcr_forall_control ))) = 1;
#line 98 "./src/main.c"
    i = 0;
#line 98 "./src/main.c"
    while(i < (((int) upcr_threads () ) * 8))
#line 98 "./src/main.c"
    {
      _bupc_Tthreads5 = upcr_threads();
      _bupc_comma0 = upcr_mythread();
      if((i % _bupc_Tthreads5) == _bupc_comma0)
      {
#line 100 "./src/main.c"
        _bupc_Mptra68 = UPCR_ADD_PSHARED1(data, 8ULL, i);
#line 100 "./src/main.c"
        _bupc_Mptra66 = UPCR_ADD_PSHARED1(data, 8ULL, i);
#line 100 "./src/main.c"
        _bupc_spillld67 = UPCR_GET_PSHARED_DOUBLEVAL(_bupc_Mptra66, 0);
        _bupc_spillstoreparm69 = _bupc_spillld67 / (_IEEE64)((((int) upcr_threads () ) * 8));
#line 100 "./src/main.c"
        UPCR_PUT_PSHARED(_bupc_Mptra68, 0, &_bupc_spillstoreparm69, 8);
#line 101 "./src/main.c"
        _bupc_Mptra72 = UPCR_ADD_PSHARED1(data, 8ULL, i + (((int) upcr_threads () ) * 8));
#line 101 "./src/main.c"
        _bupc_Mptra70 = UPCR_ADD_PSHARED1(data, 8ULL, i + (((int) upcr_threads () ) * 8));
#line 101 "./src/main.c"
        _bupc_spillld71 = UPCR_GET_PSHARED_DOUBLEVAL(_bupc_Mptra70, 0);
        _bupc_spillstoreparm73 = (-_bupc_spillld71) / (_IEEE64)((((int) upcr_threads () ) * 8));
#line 101 "./src/main.c"
        UPCR_PUT_PSHARED(_bupc_Mptra72, 0, &_bupc_spillstoreparm73, 8);
      }
#line 102 "./src/main.c"
      _2 :;
#line 102 "./src/main.c"
      i = i + 1;
    }
#line 98 "./src/main.c"
    (*((_INT32 *) UPCR_TLD_ADDR( upcr_forall_control ))) = 0;
  }
  UPCR_EXIT_FUNCTION();
  return;
} /* dft_reverse */


#line 106 "./src/main.c"
extern void fft()
#line 106 "./src/main.c"
{
#line 106 "./src/main.c"
  UPCR_BEGIN_FUNCTION();
  register _IEEE64 _bupc_comma1;
  register _IEEE64 _bupc_comma;
  register _IEEE64 _bupc_comma0;
  register _INT32 _bupc_comma2;
  int s;
  _IEEE64 _bupc__spilleq6;
  int m;
  _IEEE64 omega_m[2LL];
  int k;
  _IEEE64 omega[2LL];
  int j;
  _IEEE64 t[2LL];
  _IEEE64 u[2LL];
  int i;
  _INT32 _bupc_Tthreads7;
  upcr_pshared_ptr_t _bupc_Mptra74;
  _IEEE64 _bupc_spillld75;
  upcr_pshared_ptr_t _bupc_Mptra76;
  _IEEE64 _bupc_spillld77;
  upcr_pshared_ptr_t _bupc_Mptra78;
  _IEEE64 _bupc_spillld79;
  upcr_pshared_ptr_t _bupc_Mptra80;
  _IEEE64 _bupc_spillld81;
  upcr_pshared_ptr_t _bupc_Mptra82;
  _IEEE64 _bupc_spillld83;
  upcr_pshared_ptr_t _bupc_Mptra84;
  _IEEE64 _bupc_spillld85;
  upcr_pshared_ptr_t _bupc_Mptra86;
  _IEEE64 _bupc_spillstoreparm87;
  upcr_pshared_ptr_t _bupc_Mptra88;
  _IEEE64 _bupc_spillstoreparm89;
  upcr_pshared_ptr_t _bupc_Mptra90;
  _IEEE64 _bupc_spillstoreparm91;
  upcr_pshared_ptr_t _bupc_Mptra92;
  _IEEE64 _bupc_spillstoreparm93;
  upcr_pshared_ptr_t _bupc_Mptra94;
  _IEEE64 _bupc_spillld95;
  upcr_pshared_ptr_t _bupc_Mptra96;
  upcr_pshared_ptr_t _bupc_Mptra97;
  _IEEE64 _bupc_spillld98;
  upcr_pshared_ptr_t _bupc_Mptra99;
  
#line 107 "./src/main.c"
  bit_reversal_copy();
#line 108 "./src/main.c"
  if(((int) upcr_mythread () ) == 0)
#line 108 "./src/main.c"
  {
#line 109 "./src/main.c"
    s = 1;
#line 109 "./src/main.c"
    _bupc_comma1 = log((_IEEE64)(((int) upcr_threads () ) * 8));
#line 109 "./src/main.c"
    _bupc__spilleq6 = _bupc_comma1;
#line 109 "./src/main.c"
    while((_IEEE64)(s) <= _bupc__spilleq6)
#line 109 "./src/main.c"
    {
#line 111 "./src/main.c"
      m = _I4SHL(1, s);
#line 113 "./src/main.c"
      _bupc_comma = cos(-6.283 / (_IEEE64)(m));
#line 113 "./src/main.c"
      (omega_m)[0] = _bupc_comma;
#line 114 "./src/main.c"
      _bupc_comma0 = sin(-6.283 / (_IEEE64)(m));
#line 114 "./src/main.c"
      (omega_m)[1] = _bupc_comma0;
#line 115 "./src/main.c"
      k = 0;
#line 115 "./src/main.c"
      while(k < (((int) upcr_threads () ) * 8))
#line 115 "./src/main.c"
      {
#line 118 "./src/main.c"
        (omega)[0] = 1.0;
#line 119 "./src/main.c"
        (omega)[1] = 0.0;
#line 120 "./src/main.c"
        j = 0;
#line 120 "./src/main.c"
        while(j < (m / 2))
#line 120 "./src/main.c"
        {
#line 123 "./src/main.c"
          _bupc_Mptra74 = UPCR_ADD_PSHARED1(data_cpy, 8ULL, (k + j) + (m / 2));
#line 123 "./src/main.c"
          _bupc_spillld75 = UPCR_GET_PSHARED_DOUBLEVAL(_bupc_Mptra74, 0);
#line 123 "./src/main.c"
          _bupc_Mptra76 = UPCR_ADD_PSHARED1(data_cpy, 8ULL, ((k + j) + (m / 2)) + (((int) upcr_threads () ) * 8));
#line 123 "./src/main.c"
          _bupc_spillld77 = UPCR_GET_PSHARED_DOUBLEVAL(_bupc_Mptra76, 0);
#line 123 "./src/main.c"
          (t)[0] = ((omega)[0] * _bupc_spillld75) - ((omega)[1] * _bupc_spillld77);
#line 124 "./src/main.c"
          _bupc_Mptra78 = UPCR_ADD_PSHARED1(data_cpy, 8ULL, ((k + j) + (m / 2)) + (((int) upcr_threads () ) * 8));
#line 124 "./src/main.c"
          _bupc_spillld79 = UPCR_GET_PSHARED_DOUBLEVAL(_bupc_Mptra78, 0);
#line 124 "./src/main.c"
          _bupc_Mptra80 = UPCR_ADD_PSHARED1(data_cpy, 8ULL, (k + j) + (m / 2));
#line 124 "./src/main.c"
          _bupc_spillld81 = UPCR_GET_PSHARED_DOUBLEVAL(_bupc_Mptra80, 0);
#line 124 "./src/main.c"
          (t)[1] = ((omega)[0] * _bupc_spillld79) + ((omega)[1] * _bupc_spillld81);
#line 125 "./src/main.c"
          _bupc_Mptra82 = UPCR_ADD_PSHARED1(data_cpy, 8ULL, k + j);
#line 125 "./src/main.c"
          _bupc_spillld83 = UPCR_GET_PSHARED_DOUBLEVAL(_bupc_Mptra82, 0);
#line 125 "./src/main.c"
          (u)[0] = _bupc_spillld83;
#line 126 "./src/main.c"
          _bupc_Mptra84 = UPCR_ADD_PSHARED1(data_cpy, 8ULL, (k + j) + (((int) upcr_threads () ) * 8));
#line 126 "./src/main.c"
          _bupc_spillld85 = UPCR_GET_PSHARED_DOUBLEVAL(_bupc_Mptra84, 0);
#line 126 "./src/main.c"
          (u)[1] = _bupc_spillld85;
#line 128 "./src/main.c"
          _bupc_Mptra86 = UPCR_ADD_PSHARED1(data_cpy, 8ULL, k + j);
          _bupc_spillstoreparm87 = (u)[0] + (t)[0];
#line 128 "./src/main.c"
          UPCR_PUT_PSHARED(_bupc_Mptra86, 0, &_bupc_spillstoreparm87, 8);
#line 129 "./src/main.c"
          _bupc_Mptra88 = UPCR_ADD_PSHARED1(data_cpy, 8ULL, (k + j) + (((int) upcr_threads () ) * 8));
          _bupc_spillstoreparm89 = (u)[1] + (t)[1];
#line 129 "./src/main.c"
          UPCR_PUT_PSHARED(_bupc_Mptra88, 0, &_bupc_spillstoreparm89, 8);
#line 130 "./src/main.c"
          _bupc_Mptra90 = UPCR_ADD_PSHARED1(data_cpy, 8ULL, (k + j) + (m / 2));
          _bupc_spillstoreparm91 = (u)[0] - (t)[0];
#line 130 "./src/main.c"
          UPCR_PUT_PSHARED(_bupc_Mptra90, 0, &_bupc_spillstoreparm91, 8);
#line 131 "./src/main.c"
          _bupc_Mptra92 = UPCR_ADD_PSHARED1(data_cpy, 8ULL, ((k + j) + (m / 2)) + (((int) upcr_threads () ) * 8));
          _bupc_spillstoreparm93 = (u)[1] - (t)[1];
#line 131 "./src/main.c"
          UPCR_PUT_PSHARED(_bupc_Mptra92, 0, &_bupc_spillstoreparm93, 8);
#line 133 "./src/main.c"
          (omega)[0] = ((omega)[0] * (omega_m)[0]) - ((omega)[1] * (omega_m)[1]);
#line 134 "./src/main.c"
          (omega)[1] = ((omega)[1] * (omega_m)[0]) + ((omega)[0] * (omega_m)[1]);
#line 135 "./src/main.c"
          _3 :;
#line 135 "./src/main.c"
          j = j + 1;
        }
#line 137 "./src/main.c"
        _2 :;
#line 137 "./src/main.c"
        k = k + m;
      }
#line 138 "./src/main.c"
      _1 :;
#line 138 "./src/main.c"
      s = s + 1;
#line 109 "./src/main.c"
      _bupc_comma1 = log((_IEEE64)(((int) upcr_threads () ) * 8));
#line 109 "./src/main.c"
      _bupc__spilleq6 = _bupc_comma1;
    }
  }
#line 139 "./src/main.c"
  upcr_barrier(221775943, 1);
#line 141 "./src/main.c"
  if((*((_INT32 *) UPCR_TLD_ADDR( upcr_forall_control ))))
#line 141 "./src/main.c"
  {
#line 141 "./src/main.c"
    i = 0;
#line 141 "./src/main.c"
    while(i < (((int) upcr_threads () ) * 16))
    {
#line 143 "./src/main.c"
      _bupc_Mptra96 = UPCR_ADD_PSHARED1(data, 8ULL, i);
#line 143 "./src/main.c"
      _bupc_Mptra94 = UPCR_ADD_PSHARED1(data_cpy, 8ULL, i);
#line 143 "./src/main.c"
      _bupc_spillld95 = UPCR_GET_PSHARED_DOUBLEVAL(_bupc_Mptra94, 0);
#line 143 "./src/main.c"
      UPCR_PUT_PSHARED(_bupc_Mptra96, 0, &_bupc_spillld95, 8);
#line 144 "./src/main.c"
      _17 :;
#line 144 "./src/main.c"
      i = i + 1;
    }
  }
  else
#line 141 "./src/main.c"
  {
#line 141 "./src/main.c"
    (*((_INT32 *) UPCR_TLD_ADDR( upcr_forall_control ))) = 1;
#line 141 "./src/main.c"
    i = 0;
#line 141 "./src/main.c"
    while(i < (((int) upcr_threads () ) * 16))
#line 141 "./src/main.c"
    {
      _bupc_Tthreads7 = upcr_threads();
      _bupc_comma2 = upcr_mythread();
      if((i % _bupc_Tthreads7) == _bupc_comma2)
      {
#line 143 "./src/main.c"
        _bupc_Mptra99 = UPCR_ADD_PSHARED1(data, 8ULL, i);
#line 143 "./src/main.c"
        _bupc_Mptra97 = UPCR_ADD_PSHARED1(data_cpy, 8ULL, i);
#line 143 "./src/main.c"
        _bupc_spillld98 = UPCR_GET_PSHARED_DOUBLEVAL(_bupc_Mptra97, 0);
#line 143 "./src/main.c"
        UPCR_PUT_PSHARED(_bupc_Mptra99, 0, &_bupc_spillld98, 8);
      }
#line 144 "./src/main.c"
      _4 :;
#line 144 "./src/main.c"
      i = i + 1;
    }
#line 141 "./src/main.c"
    (*((_INT32 *) UPCR_TLD_ADDR( upcr_forall_control ))) = 0;
  }
  UPCR_EXIT_FUNCTION();
  return;
} /* fft */


#line 148 "./src/main.c"
extern void fft_reverse()
#line 148 "./src/main.c"
{
#line 148 "./src/main.c"
  UPCR_BEGIN_FUNCTION();
  
  UPCR_EXIT_FUNCTION();
  return;
} /* fft_reverse */


#line 153 "./src/main.c"
extern int bit_reverse(
  int num)
#line 153 "./src/main.c"
{
#line 153 "./src/main.c"
  UPCR_BEGIN_FUNCTION();
  register _IEEE64 _bupc_comma;
  int N_bits;
  int num_rev;
  int i;
  int curr_bit;
  
#line 154 "./src/main.c"
  _bupc_comma = log2((_IEEE64)(((int) upcr_threads () ) * 8));
#line 154 "./src/main.c"
  N_bits = _I4F8TRUNC(_bupc_comma);
#line 156 "./src/main.c"
  num_rev = 0;
#line 157 "./src/main.c"
  i = 0;
#line 157 "./src/main.c"
  while(i < N_bits)
#line 157 "./src/main.c"
  {
#line 159 "./src/main.c"
    curr_bit = _I4ASHR(num, i) & 1;
#line 160 "./src/main.c"
    num_rev = num_rev + _I4SHL(curr_bit, (N_bits - i) + -1);
#line 161 "./src/main.c"
    _1 :;
#line 161 "./src/main.c"
    i = i + 1;
  }
#line 162 "./src/main.c"
  UPCR_EXIT_FUNCTION();
#line 162 "./src/main.c"
  return num_rev;
} /* bit_reverse */


#line 166 "./src/main.c"
extern void bit_reversal_copy()
#line 166 "./src/main.c"
{
#line 166 "./src/main.c"
  UPCR_BEGIN_FUNCTION();
  register _INT32 _bupc_comma;
  register _INT32 _bupc_comma0;
  register _INT32 _bupc_comma1;
  int i;
  _INT32 _bupc_Tthreads8;
  int i_rev;
  int _bupc_w2c_i0;
  _INT32 _bupc_Tthreads9;
  upcr_pshared_ptr_t _bupc_Mptra100;
  _IEEE64 _bupc_spillld101;
  upcr_pshared_ptr_t _bupc_Mptra102;
  upcr_pshared_ptr_t _bupc_Mptra103;
  _IEEE64 _bupc_spillld104;
  upcr_pshared_ptr_t _bupc_Mptra105;
  upcr_pshared_ptr_t _bupc_Mptra106;
  _IEEE64 _bupc_spillld107;
  upcr_pshared_ptr_t _bupc_Mptra108;
  upcr_pshared_ptr_t _bupc_Mptra109;
  _IEEE64 _bupc_spillld110;
  upcr_pshared_ptr_t _bupc_Mptra111;
  upcr_pshared_ptr_t _bupc_Mptra112;
  _IEEE64 _bupc_spillld113;
  upcr_pshared_ptr_t _bupc_Mptra114;
  upcr_pshared_ptr_t _bupc_Mptra115;
  _IEEE64 _bupc_spillld116;
  upcr_pshared_ptr_t _bupc_Mptra117;
  upcr_pshared_ptr_t _bupc_Mptra118;
  _IEEE64 _bupc_spillld119;
  upcr_pshared_ptr_t _bupc_Mptra120;
  upcr_pshared_ptr_t _bupc_Mptra121;
  _IEEE64 _bupc_spillld122;
  upcr_pshared_ptr_t _bupc_Mptra123;
  
#line 167 "./src/main.c"
  if((*((_INT32 *) UPCR_TLD_ADDR( upcr_forall_control ))))
#line 167 "./src/main.c"
  {
#line 167 "./src/main.c"
    i = 0;
#line 167 "./src/main.c"
    while(i < (((int) upcr_threads () ) * 8))
    {
#line 169 "./src/main.c"
      _bupc_comma = bit_reverse(i);
#line 169 "./src/main.c"
      i_rev = _bupc_comma;
#line 170 "./src/main.c"
      _bupc_Mptra102 = UPCR_ADD_PSHARED1(data_cpy, 8ULL, i_rev);
#line 170 "./src/main.c"
      _bupc_Mptra100 = UPCR_ADD_PSHARED1(data, 8ULL, i);
#line 170 "./src/main.c"
      _bupc_spillld101 = UPCR_GET_PSHARED_DOUBLEVAL(_bupc_Mptra100, 0);
#line 170 "./src/main.c"
      UPCR_PUT_PSHARED(_bupc_Mptra102, 0, &_bupc_spillld101, 8);
#line 171 "./src/main.c"
      _bupc_Mptra105 = UPCR_ADD_PSHARED1(data_cpy, 8ULL, i_rev + (((int) upcr_threads () ) * 8));
#line 171 "./src/main.c"
      _bupc_Mptra103 = UPCR_ADD_PSHARED1(data, 8ULL, i + (((int) upcr_threads () ) * 8));
#line 171 "./src/main.c"
      _bupc_spillld104 = UPCR_GET_PSHARED_DOUBLEVAL(_bupc_Mptra103, 0);
#line 171 "./src/main.c"
      UPCR_PUT_PSHARED(_bupc_Mptra105, 0, &_bupc_spillld104, 8);
#line 172 "./src/main.c"
      _11 :;
#line 172 "./src/main.c"
      i = i + 1;
    }
  }
  else
#line 167 "./src/main.c"
  {
#line 167 "./src/main.c"
    (*((_INT32 *) UPCR_TLD_ADDR( upcr_forall_control ))) = 1;
#line 167 "./src/main.c"
    i = 0;
#line 167 "./src/main.c"
    while(i < (((int) upcr_threads () ) * 8))
#line 167 "./src/main.c"
    {
      _bupc_Tthreads8 = upcr_threads();
      _bupc_comma0 = upcr_mythread();
      if((i % _bupc_Tthreads8) == _bupc_comma0)
      {
#line 169 "./src/main.c"
        _bupc_comma = bit_reverse(i);
#line 169 "./src/main.c"
        i_rev = _bupc_comma;
#line 170 "./src/main.c"
        _bupc_Mptra108 = UPCR_ADD_PSHARED1(data_cpy, 8ULL, i_rev);
#line 170 "./src/main.c"
        _bupc_Mptra106 = UPCR_ADD_PSHARED1(data, 8ULL, i);
#line 170 "./src/main.c"
        _bupc_spillld107 = UPCR_GET_PSHARED_DOUBLEVAL(_bupc_Mptra106, 0);
#line 170 "./src/main.c"
        UPCR_PUT_PSHARED(_bupc_Mptra108, 0, &_bupc_spillld107, 8);
#line 171 "./src/main.c"
        _bupc_Mptra111 = UPCR_ADD_PSHARED1(data_cpy, 8ULL, i_rev + (((int) upcr_threads () ) * 8));
#line 171 "./src/main.c"
        _bupc_Mptra109 = UPCR_ADD_PSHARED1(data, 8ULL, i + (((int) upcr_threads () ) * 8));
#line 171 "./src/main.c"
        _bupc_spillld110 = UPCR_GET_PSHARED_DOUBLEVAL(_bupc_Mptra109, 0);
#line 171 "./src/main.c"
        UPCR_PUT_PSHARED(_bupc_Mptra111, 0, &_bupc_spillld110, 8);
      }
#line 172 "./src/main.c"
      _1 :;
#line 172 "./src/main.c"
      i = i + 1;
    }
#line 167 "./src/main.c"
    (*((_INT32 *) UPCR_TLD_ADDR( upcr_forall_control ))) = 0;
  }
#line 173 "./src/main.c"
  upcr_barrier(221775944, 1);
#line 174 "./src/main.c"
  if((*((_INT32 *) UPCR_TLD_ADDR( upcr_forall_control ))))
#line 174 "./src/main.c"
  {
#line 174 "./src/main.c"
    _bupc_w2c_i0 = 0;
#line 174 "./src/main.c"
    while(_bupc_w2c_i0 < (((int) upcr_threads () ) * 8))
    {
#line 176 "./src/main.c"
      _bupc_Mptra114 = UPCR_ADD_PSHARED1(data, 8ULL, _bupc_w2c_i0);
#line 176 "./src/main.c"
      _bupc_Mptra112 = UPCR_ADD_PSHARED1(data_cpy, 8ULL, _bupc_w2c_i0);
#line 176 "./src/main.c"
      _bupc_spillld113 = UPCR_GET_PSHARED_DOUBLEVAL(_bupc_Mptra112, 0);
#line 176 "./src/main.c"
      UPCR_PUT_PSHARED(_bupc_Mptra114, 0, &_bupc_spillld113, 8);
#line 177 "./src/main.c"
      _bupc_Mptra117 = UPCR_ADD_PSHARED1(data, 8ULL, _bupc_w2c_i0 + (((int) upcr_threads () ) * 8));
#line 177 "./src/main.c"
      _bupc_Mptra115 = UPCR_ADD_PSHARED1(data_cpy, 8ULL, _bupc_w2c_i0 + (((int) upcr_threads () ) * 8));
#line 177 "./src/main.c"
      _bupc_spillld116 = UPCR_GET_PSHARED_DOUBLEVAL(_bupc_Mptra115, 0);
#line 177 "./src/main.c"
      UPCR_PUT_PSHARED(_bupc_Mptra117, 0, &_bupc_spillld116, 8);
#line 178 "./src/main.c"
      _12 :;
#line 178 "./src/main.c"
      _bupc_w2c_i0 = _bupc_w2c_i0 + 1;
    }
  }
  else
#line 174 "./src/main.c"
  {
#line 174 "./src/main.c"
    (*((_INT32 *) UPCR_TLD_ADDR( upcr_forall_control ))) = 1;
#line 174 "./src/main.c"
    _bupc_w2c_i0 = 0;
#line 174 "./src/main.c"
    while(_bupc_w2c_i0 < (((int) upcr_threads () ) * 8))
#line 174 "./src/main.c"
    {
      _bupc_Tthreads9 = upcr_threads();
      _bupc_comma1 = upcr_mythread();
      if((_bupc_w2c_i0 % _bupc_Tthreads9) == _bupc_comma1)
      {
#line 176 "./src/main.c"
        _bupc_Mptra120 = UPCR_ADD_PSHARED1(data, 8ULL, _bupc_w2c_i0);
#line 176 "./src/main.c"
        _bupc_Mptra118 = UPCR_ADD_PSHARED1(data_cpy, 8ULL, _bupc_w2c_i0);
#line 176 "./src/main.c"
        _bupc_spillld119 = UPCR_GET_PSHARED_DOUBLEVAL(_bupc_Mptra118, 0);
#line 176 "./src/main.c"
        UPCR_PUT_PSHARED(_bupc_Mptra120, 0, &_bupc_spillld119, 8);
#line 177 "./src/main.c"
        _bupc_Mptra123 = UPCR_ADD_PSHARED1(data, 8ULL, _bupc_w2c_i0 + (((int) upcr_threads () ) * 8));
#line 177 "./src/main.c"
        _bupc_Mptra121 = UPCR_ADD_PSHARED1(data_cpy, 8ULL, _bupc_w2c_i0 + (((int) upcr_threads () ) * 8));
#line 177 "./src/main.c"
        _bupc_spillld122 = UPCR_GET_PSHARED_DOUBLEVAL(_bupc_Mptra121, 0);
#line 177 "./src/main.c"
        UPCR_PUT_PSHARED(_bupc_Mptra123, 0, &_bupc_spillld122, 8);
      }
#line 178 "./src/main.c"
      _2 :;
#line 178 "./src/main.c"
      _bupc_w2c_i0 = _bupc_w2c_i0 + 1;
    }
#line 174 "./src/main.c"
    (*((_INT32 *) UPCR_TLD_ADDR( upcr_forall_control ))) = 0;
  }
#line 179 "./src/main.c"
  upcr_barrier(221775945, 1);
  UPCR_EXIT_FUNCTION();
  return;
} /* bit_reversal_copy */


#line 183 "./src/main.c"
extern void print_data(
  const char * filename)
#line 183 "./src/main.c"
{
#line 183 "./src/main.c"
  UPCR_BEGIN_FUNCTION();
  struct _IO_FILE * f;
  int i;
  struct _IO_FILE * _bupc_call124;
  upcr_pshared_ptr_t _bupc_Mptra125;
  _IEEE64 _bupc_spillld126;
  upcr_pshared_ptr_t _bupc_Mptra127;
  _IEEE64 _bupc_spillld128;
  
#line 184 "./src/main.c"
  if(((int) upcr_mythread () ) == 0)
#line 184 "./src/main.c"
  {
#line 186 "./src/main.c"
    _bupc_call124 = fopen(filename, "w");
#line 186 "./src/main.c"
    f = _bupc_call124;
#line 187 "./src/main.c"
    i = 0;
#line 187 "./src/main.c"
    while(i < (((int) upcr_threads () ) * 8))
#line 187 "./src/main.c"
    {
#line 189 "./src/main.c"
      _bupc_Mptra125 = UPCR_ADD_PSHARED1(data, 8ULL, i);
#line 189 "./src/main.c"
      _bupc_spillld126 = UPCR_GET_PSHARED_DOUBLEVAL(_bupc_Mptra125, 0);
#line 189 "./src/main.c"
      _bupc_Mptra127 = UPCR_ADD_PSHARED1(data, 8ULL, i + (((int) upcr_threads () ) * 8));
#line 189 "./src/main.c"
      _bupc_spillld128 = UPCR_GET_PSHARED_DOUBLEVAL(_bupc_Mptra127, 0);
#line 189 "./src/main.c"
      fprintf(f, "%d,\t%lf,\t%lf\n", i, _bupc_spillld126, _bupc_spillld128);
#line 190 "./src/main.c"
      _1 :;
#line 190 "./src/main.c"
      i = i + 1;
    }
#line 191 "./src/main.c"
    fclose(f);
  }
  UPCR_EXIT_FUNCTION();
  return;
} /* print_data */

#line 1 "_SYSTEM"
/**************************************************************************/
/* upcc-generated strings for configuration consistency checks            */

GASNETT_IDENT(UPCRI_IdentString_main_o_1655807543_GASNetConfig_gen, 
 "$GASNetConfig: (/tmp/upcc--446970-1655807542/main.trans.c) RELEASE=2022.3.0,SPEC=0.15,CONDUIT=MPI(MPI-2.9/REFERENCE-2022.3),THREADMODEL=PAR,SEGMENT=FAST,PTR=64bit,CACHE_LINE_BYTES=64,noalign,pshm,nodebug,notrace,nostats,nodebugmalloc,nosrclines,timers_native,membars_native,atomics_native,atomic32_native,atomic64_native,notiopt $");
GASNETT_IDENT(UPCRI_IdentString_main_o_1655807543_UPCRConfig_gen,
 "$UPCRConfig: (/tmp/upcc--446970-1655807542/main.trans.c) VERSION=2022.5.0,PLATFORMENV=shared-distributed,SHMEM=pthreads/pshm,SHAREDPTRREP=packed/p20:t10:a34,TRANS=berkeleyupc,nodebug,nogasp,dynamicthreads $");
GASNETT_IDENT(UPCRI_IdentString_main_o_1655807543_translatetime, 
 "$UPCTranslateTime: (main.o) Tue Jun 21 03:32:23 2022 $");
GASNETT_IDENT(UPCRI_IdentString_main_o_1655807543_GASNetConfig_obj, 
 "$GASNetConfig: (main.o) " GASNET_CONFIG_STRING " $");
GASNETT_IDENT(UPCRI_IdentString_main_o_1655807543_UPCRConfig_obj,
 "$UPCRConfig: (main.o) " UPCR_CONFIG_STRING UPCRI_THREADCONFIG_STR " $");
GASNETT_IDENT(UPCRI_IdentString_main_o_1655807543_translator, 
 "$UPCTranslator: (main.o) /usr/local/upc/2020.12.0/translator/install/targ (aphid.lbl.gov) $");
GASNETT_IDENT(UPCRI_IdentString_main_o_1655807543_upcver, 
 "$UPCVersion: (main.o) 2020.12.0 $");
GASNETT_IDENT(UPCRI_IdentString_main_o_1655807543_compileline, 
 "$UPCCompileLine: (main.o) /usr/local/upc/2020.12.0/runtime/inst/bin/upcc.pl --at-remote-http -translator=/usr/local/upc/2020.12.0/translator/install/targ --arch-size=64 --network=mpi --pthreads 4 --lines --trans --sizes-file=upcc-sizes main.i $");
GASNETT_IDENT(UPCRI_IdentString_main_o_1655807543_compiletime, 
 "$UPCCompileTime: (main.o) " __DATE__ " " __TIME__ " $");
#ifndef UPCRI_CC /* ensure backward compatilibity for http netcompile */
#define UPCRI_CC <unknown>
#endif
GASNETT_IDENT(UPCRI_IdentString_main_o_1655807543_backendcompiler, 
 "$UPCRBackendCompiler: (main.o) " _STRINGIFY(UPCRI_CC) " $");

#ifdef GASNETT_CONFIGURE_MISMATCH
  GASNETT_IDENT(UPCRI_IdentString_main_o_1655807543_configuremismatch, 
   "$UPCRConfigureMismatch: (main.o) 1 $");
  GASNETT_IDENT(UPCRI_IdentString_main_o_1655807543_configuredcompiler, 
   "$UPCRConfigureCompiler: (main.o) " GASNETT_PLATFORM_COMPILER_IDSTR " $");
  GASNETT_IDENT(UPCRI_IdentString_main_o_1655807543_buildcompiler, 
   "$UPCRBuildCompiler: (main.o) " PLATFORM_COMPILER_IDSTR " $");
#endif

/**************************************************************************/
GASNETT_IDENT(UPCRI_IdentString_main_o_1655807543_transver_2,
 "$UPCTranslatorVersion: (main.o) 2.28.2, built on Dec 11 2020 at 14:19:36, host aphid.lbl.gov linux-x86_64/64, gcc v9.3.0 $");
GASNETT_IDENT(UPCRI_IdentString_main_o_1655807543_shareddata_data,
 "$UPCRStaticSharedData: (data) 8 16 1 8 A16H_R1_d $");
GASNETT_IDENT(UPCRI_IdentString_main_o_1655807543_shareddata_data_cpy,
 "$UPCRStaticSharedData: (data_cpy) 8 16 1 8 A16H_R1_d $");
GASNETT_IDENT(UPCRI_IdentString_INIT_main_6953773828161,"$UPCRInitFn: (main.trans.c) UPCRI_INIT_main_6953773828161 $");
GASNETT_IDENT(UPCRI_IdentString_ALLOC_main_6953773828161,"$UPCRAllocFn: (main.trans.c) UPCRI_ALLOC_main_6953773828161 $");
