/* --- UPCR system headers --- */ 
#include "upcr.h" 
#include "whirl2c.h"
#include "upcr_proxy.h"
/*******************************************************
 * C file translated from WHIRL Tue Jun 21 04:23:43 2022
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

extern void fft_reverse();

extern void dft();

extern void dft_reverse();

extern void bit_reversal_copy();

extern int bit_reverse(int);


#define UPCR_SHARED_SIZE_ 8
#define UPCR_PSHARED_SIZE_ 8
upcr_pshared_ptr_t data;
upcr_pshared_ptr_t data_cpy;

void UPCRI_ALLOC_main_6953773828161(void) { 
UPCR_BEGIN_FUNCTION();
upcr_startup_pshalloc_t _bupc_pinfo[] = { 
UPCRT_STARTUP_PSHALLOC(data, 8, 512, 1, 8, "A512H_R1_d"), 
UPCRT_STARTUP_PSHALLOC(data_cpy, 8, 512, 1, 8, "A512H_R1_d"), 
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
    while(i < (((int) upcr_threads () ) * 256))
    {
#line 31 "./src/main.c"
      _bupc_comma = sin(((_IEEE64)(i) * 6.28318530718) / (_IEEE64)((((int) upcr_threads () ) * 256)));
#line 31 "./src/main.c"
      _bupc_Mptra0 = UPCR_ADD_PSHARED1(data, 8ULL, i);
      UPCR_PUT_PSHARED_DOUBLEVAL(_bupc_Mptra0, 0, _bupc_comma);
#line 32 "./src/main.c"
      _bupc_Mptra1 = UPCR_ADD_PSHARED1(data, 8ULL, i + (((int) upcr_threads () ) * 256));
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
    while(i < (((int) upcr_threads () ) * 256))
#line 29 "./src/main.c"
    {
      _bupc_Tthreads0 = upcr_threads();
      _bupc_comma0 = upcr_mythread();
      if((i % _bupc_Tthreads0) == _bupc_comma0)
      {
#line 31 "./src/main.c"
        _bupc_comma = sin(((_IEEE64)(i) * 6.28318530718) / (_IEEE64)((((int) upcr_threads () ) * 256)));
#line 31 "./src/main.c"
        _bupc_Mptra3 = UPCR_ADD_PSHARED1(data, 8ULL, i);
        UPCR_PUT_PSHARED_DOUBLEVAL(_bupc_Mptra3, 0, _bupc_comma);
#line 32 "./src/main.c"
        _bupc_Mptra4 = UPCR_ADD_PSHARED1(data, 8ULL, i + (((int) upcr_threads () ) * 256));
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
  fft_reverse();
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
    while(k < (((int) upcr_threads () ) * 256))
    {
#line 60 "./src/main.c"
      _bupc_Mptra6 = UPCR_ADD_PSHARED1(data_cpy, 8ULL, k);
      _bupc_spillstoreparm7 = 0.0;
#line 60 "./src/main.c"
      UPCR_PUT_PSHARED(_bupc_Mptra6, 0, &_bupc_spillstoreparm7, 8);
#line 61 "./src/main.c"
      _bupc_Mptra8 = UPCR_ADD_PSHARED1(data_cpy, 8ULL, k + (((int) upcr_threads () ) * 256));
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
    while(k < (((int) upcr_threads () ) * 256))
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
        _bupc_Mptra12 = UPCR_ADD_PSHARED1(data_cpy, 8ULL, k + (((int) upcr_threads () ) * 256));
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
    while(_bupc_w2c_k0 < (((int) upcr_threads () ) * 256))
    {
#line 69 "./src/main.c"
      (c)[0] = 0.0;
#line 70 "./src/main.c"
      (c)[1] = 0.0;
#line 71 "./src/main.c"
      n = 0;
#line 71 "./src/main.c"
      while(n < (((int) upcr_threads () ) * 256))
#line 71 "./src/main.c"
      {
#line 73 "./src/main.c"
        arg = (((_IEEE64)(_bupc_w2c_k0) * -6.28318530718) * (_IEEE64)(n)) / (_IEEE64)((((int) upcr_threads () ) * 256));
#line 74 "./src/main.c"
        _bupc_comma0 = cos(arg);
#line 74 "./src/main.c"
        _bupc_comma1 = sin(arg);
#line 74 "./src/main.c"
        _bupc_Mptra14 = UPCR_ADD_PSHARED1(data, 8ULL, n);
#line 74 "./src/main.c"
        _bupc_spillld15 = UPCR_GET_PSHARED_DOUBLEVAL(_bupc_Mptra14, 0);
#line 74 "./src/main.c"
        _bupc_Mptra16 = UPCR_ADD_PSHARED1(data, 8ULL, n + (((int) upcr_threads () ) * 256));
#line 74 "./src/main.c"
        _bupc_spillld17 = UPCR_GET_PSHARED_DOUBLEVAL(_bupc_Mptra16, 0);
#line 74 "./src/main.c"
        (c)[0] = (c)[0] + ((_bupc_spillld15 * _bupc_comma0) - (_bupc_spillld17 * _bupc_comma1));
#line 75 "./src/main.c"
        _bupc_comma2 = cos(arg);
#line 75 "./src/main.c"
        _bupc_comma3 = sin(arg);
#line 75 "./src/main.c"
        _bupc_Mptra18 = UPCR_ADD_PSHARED1(data, 8ULL, n + (((int) upcr_threads () ) * 256));
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
      _bupc_Mptra24 = UPCR_ADD_PSHARED1(data_cpy, 8ULL, _bupc_w2c_k0 + (((int) upcr_threads () ) * 256));
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
    while(_bupc_w2c_k0 < (((int) upcr_threads () ) * 256))
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
        while(n < (((int) upcr_threads () ) * 256))
#line 71 "./src/main.c"
        {
#line 73 "./src/main.c"
          arg = (((_IEEE64)(_bupc_w2c_k0) * -6.28318530718) * (_IEEE64)(n)) / (_IEEE64)((((int) upcr_threads () ) * 256));
#line 74 "./src/main.c"
          _bupc_comma0 = cos(arg);
#line 74 "./src/main.c"
          _bupc_comma1 = sin(arg);
#line 74 "./src/main.c"
          _bupc_Mptra26 = UPCR_ADD_PSHARED1(data, 8ULL, n);
#line 74 "./src/main.c"
          _bupc_spillld27 = UPCR_GET_PSHARED_DOUBLEVAL(_bupc_Mptra26, 0);
#line 74 "./src/main.c"
          _bupc_Mptra28 = UPCR_ADD_PSHARED1(data, 8ULL, n + (((int) upcr_threads () ) * 256));
#line 74 "./src/main.c"
          _bupc_spillld29 = UPCR_GET_PSHARED_DOUBLEVAL(_bupc_Mptra28, 0);
#line 74 "./src/main.c"
          (c)[0] = (c)[0] + ((_bupc_spillld27 * _bupc_comma0) - (_bupc_spillld29 * _bupc_comma1));
#line 75 "./src/main.c"
          _bupc_comma2 = cos(arg);
#line 75 "./src/main.c"
          _bupc_comma3 = sin(arg);
#line 75 "./src/main.c"
          _bupc_Mptra30 = UPCR_ADD_PSHARED1(data, 8ULL, n + (((int) upcr_threads () ) * 256));
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
        _bupc_Mptra36 = UPCR_ADD_PSHARED1(data_cpy, 8ULL, _bupc_w2c_k0 + (((int) upcr_threads () ) * 256));
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
    while(_bupc_w2c_k1 < (((int) upcr_threads () ) * 256))
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
      _bupc_Mptra43 = UPCR_ADD_PSHARED1(data, 8ULL, _bupc_w2c_k1 + (((int) upcr_threads () ) * 256));
#line 84 "./src/main.c"
      _bupc_Mptra41 = UPCR_ADD_PSHARED1(data_cpy, 8ULL, _bupc_w2c_k1 + (((int) upcr_threads () ) * 256));
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
    while(_bupc_w2c_k1 < (((int) upcr_threads () ) * 256))
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
        _bupc_Mptra49 = UPCR_ADD_PSHARED1(data, 8ULL, _bupc_w2c_k1 + (((int) upcr_threads () ) * 256));
#line 84 "./src/main.c"
        _bupc_Mptra47 = UPCR_ADD_PSHARED1(data_cpy, 8ULL, _bupc_w2c_k1 + (((int) upcr_threads () ) * 256));
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
    while(i < (((int) upcr_threads () ) * 256))
    {
#line 94 "./src/main.c"
      _bupc_Mptra52 = UPCR_ADD_PSHARED1(data, 8ULL, i + (((int) upcr_threads () ) * 256));
#line 94 "./src/main.c"
      _bupc_Mptra50 = UPCR_ADD_PSHARED1(data, 8ULL, i + (((int) upcr_threads () ) * 256));
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
    while(i < (((int) upcr_threads () ) * 256))
#line 92 "./src/main.c"
    {
      _bupc_Tthreads4 = upcr_threads();
      _bupc_comma = upcr_mythread();
      if((i % _bupc_Tthreads4) == _bupc_comma)
      {
#line 94 "./src/main.c"
        _bupc_Mptra56 = UPCR_ADD_PSHARED1(data, 8ULL, i + (((int) upcr_threads () ) * 256));
#line 94 "./src/main.c"
        _bupc_Mptra54 = UPCR_ADD_PSHARED1(data, 8ULL, i + (((int) upcr_threads () ) * 256));
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
    while(i < (((int) upcr_threads () ) * 256))
    {
#line 100 "./src/main.c"
      _bupc_Mptra60 = UPCR_ADD_PSHARED1(data, 8ULL, i);
#line 100 "./src/main.c"
      _bupc_Mptra58 = UPCR_ADD_PSHARED1(data, 8ULL, i);
#line 100 "./src/main.c"
      _bupc_spillld59 = UPCR_GET_PSHARED_DOUBLEVAL(_bupc_Mptra58, 0);
      _bupc_spillstoreparm61 = _bupc_spillld59 / (_IEEE64)((((int) upcr_threads () ) * 256));
#line 100 "./src/main.c"
      UPCR_PUT_PSHARED(_bupc_Mptra60, 0, &_bupc_spillstoreparm61, 8);
#line 101 "./src/main.c"
      _bupc_Mptra64 = UPCR_ADD_PSHARED1(data, 8ULL, i + (((int) upcr_threads () ) * 256));
#line 101 "./src/main.c"
      _bupc_Mptra62 = UPCR_ADD_PSHARED1(data, 8ULL, i + (((int) upcr_threads () ) * 256));
#line 101 "./src/main.c"
      _bupc_spillld63 = UPCR_GET_PSHARED_DOUBLEVAL(_bupc_Mptra62, 0);
      _bupc_spillstoreparm65 = (-_bupc_spillld63) / (_IEEE64)((((int) upcr_threads () ) * 256));
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
    while(i < (((int) upcr_threads () ) * 256))
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
        _bupc_spillstoreparm69 = _bupc_spillld67 / (_IEEE64)((((int) upcr_threads () ) * 256));
#line 100 "./src/main.c"
        UPCR_PUT_PSHARED(_bupc_Mptra68, 0, &_bupc_spillstoreparm69, 8);
#line 101 "./src/main.c"
        _bupc_Mptra72 = UPCR_ADD_PSHARED1(data, 8ULL, i + (((int) upcr_threads () ) * 256));
#line 101 "./src/main.c"
        _bupc_Mptra70 = UPCR_ADD_PSHARED1(data, 8ULL, i + (((int) upcr_threads () ) * 256));
#line 101 "./src/main.c"
        _bupc_spillld71 = UPCR_GET_PSHARED_DOUBLEVAL(_bupc_Mptra70, 0);
        _bupc_spillstoreparm73 = (-_bupc_spillld71) / (_IEEE64)((((int) upcr_threads () ) * 256));
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
  register _INT32 _bupc_comma;
  register _IEEE64 _bupc_comma3;
  register _IEEE64 _bupc_comma0;
  register _IEEE64 _bupc_comma1;
  register _INT32 _bupc_comma2;
  register _INT32 _bupc_comma4;
  int i;
  _INT32 _bupc_Tthreads6;
  int s;
  _IEEE64 _bupc__spilleq7;
  int m;
  _IEEE64 omega_m[2LL];
  int k;
  _INT32 _bupc_Tthreads8;
  _IEEE64 omega[2LL];
  int j;
  _IEEE64 t[2LL];
  _IEEE64 u[2LL];
  _IEEE64 tmp[2LL];
  int _bupc_w2c_i0;
  _INT32 _bupc_Tthreads9;
  upcr_pshared_ptr_t _bupc_Mptra74;
  _IEEE64 _bupc_spillld75;
  upcr_pshared_ptr_t _bupc_Mptra76;
  upcr_pshared_ptr_t _bupc_Mptra77;
  _IEEE64 _bupc_spillld78;
  upcr_pshared_ptr_t _bupc_Mptra79;
  upcr_pshared_ptr_t _bupc_Mptra80;
  _IEEE64 _bupc_spillld81;
  upcr_pshared_ptr_t _bupc_Mptra82;
  upcr_pshared_ptr_t _bupc_Mptra83;
  _IEEE64 _bupc_spillld84;
  upcr_pshared_ptr_t _bupc_Mptra85;
  upcr_pshared_ptr_t _bupc_Mptra86;
  _IEEE64 _bupc_spillld87;
  upcr_pshared_ptr_t _bupc_Mptra88;
  _IEEE64 _bupc_spillld89;
  upcr_pshared_ptr_t _bupc_Mptra90;
  _IEEE64 _bupc_spillld91;
  upcr_pshared_ptr_t _bupc_Mptra92;
  _IEEE64 _bupc_spillld93;
  upcr_pshared_ptr_t _bupc_Mptra94;
  _IEEE64 _bupc_spillld95;
  upcr_pshared_ptr_t _bupc_Mptra96;
  _IEEE64 _bupc_spillld97;
  upcr_pshared_ptr_t _bupc_Mptra98;
  _IEEE64 _bupc_spillstoreparm99;
  upcr_pshared_ptr_t _bupc_Mptra100;
  _IEEE64 _bupc_spillstoreparm101;
  upcr_pshared_ptr_t _bupc_Mptra102;
  _IEEE64 _bupc_spillstoreparm103;
  upcr_pshared_ptr_t _bupc_Mptra104;
  _IEEE64 _bupc_spillstoreparm105;
  upcr_pshared_ptr_t _bupc_Mptra106;
  _IEEE64 _bupc_spillld107;
  upcr_pshared_ptr_t _bupc_Mptra108;
  _IEEE64 _bupc_spillld109;
  upcr_pshared_ptr_t _bupc_Mptra110;
  _IEEE64 _bupc_spillld111;
  upcr_pshared_ptr_t _bupc_Mptra112;
  _IEEE64 _bupc_spillld113;
  upcr_pshared_ptr_t _bupc_Mptra114;
  _IEEE64 _bupc_spillld115;
  upcr_pshared_ptr_t _bupc_Mptra116;
  _IEEE64 _bupc_spillld117;
  upcr_pshared_ptr_t _bupc_Mptra118;
  _IEEE64 _bupc_spillstoreparm119;
  upcr_pshared_ptr_t _bupc_Mptra120;
  _IEEE64 _bupc_spillstoreparm121;
  upcr_pshared_ptr_t _bupc_Mptra122;
  _IEEE64 _bupc_spillstoreparm123;
  upcr_pshared_ptr_t _bupc_Mptra124;
  _IEEE64 _bupc_spillstoreparm125;
  upcr_pshared_ptr_t _bupc_Mptra126;
  _IEEE64 _bupc_spillld127;
  upcr_pshared_ptr_t _bupc_Mptra128;
  upcr_pshared_ptr_t _bupc_Mptra129;
  _IEEE64 _bupc_spillld130;
  upcr_pshared_ptr_t _bupc_Mptra131;
  upcr_pshared_ptr_t _bupc_Mptra132;
  _IEEE64 _bupc_spillld133;
  upcr_pshared_ptr_t _bupc_Mptra134;
  upcr_pshared_ptr_t _bupc_Mptra135;
  _IEEE64 _bupc_spillld136;
  upcr_pshared_ptr_t _bupc_Mptra137;
  
#line 107 "./src/main.c"
  if((*((_INT32 *) UPCR_TLD_ADDR( upcr_forall_control ))))
#line 107 "./src/main.c"
  {
#line 107 "./src/main.c"
    i = 0;
#line 107 "./src/main.c"
    while(i < (((int) upcr_threads () ) * 256))
    {
#line 109 "./src/main.c"
      _bupc_Mptra76 = UPCR_ADD_PSHARED1(data_cpy, 8ULL, i);
#line 109 "./src/main.c"
      _bupc_Mptra74 = UPCR_ADD_PSHARED1(data, 8ULL, i);
#line 109 "./src/main.c"
      _bupc_spillld75 = UPCR_GET_PSHARED_DOUBLEVAL(_bupc_Mptra74, 0);
#line 109 "./src/main.c"
      UPCR_PUT_PSHARED(_bupc_Mptra76, 0, &_bupc_spillld75, 8);
#line 110 "./src/main.c"
      _bupc_Mptra79 = UPCR_ADD_PSHARED1(data_cpy, 8ULL, i + (((int) upcr_threads () ) * 256));
#line 110 "./src/main.c"
      _bupc_Mptra77 = UPCR_ADD_PSHARED1(data, 8ULL, i + (((int) upcr_threads () ) * 256));
#line 110 "./src/main.c"
      _bupc_spillld78 = UPCR_GET_PSHARED_DOUBLEVAL(_bupc_Mptra77, 0);
#line 110 "./src/main.c"
      UPCR_PUT_PSHARED(_bupc_Mptra79, 0, &_bupc_spillld78, 8);
#line 111 "./src/main.c"
      _24 :;
#line 111 "./src/main.c"
      i = i + 1;
    }
  }
  else
#line 107 "./src/main.c"
  {
#line 107 "./src/main.c"
    (*((_INT32 *) UPCR_TLD_ADDR( upcr_forall_control ))) = 1;
#line 107 "./src/main.c"
    i = 0;
#line 107 "./src/main.c"
    while(i < (((int) upcr_threads () ) * 256))
#line 107 "./src/main.c"
    {
      _bupc_Tthreads6 = upcr_threads();
      _bupc_comma = upcr_mythread();
      if((i % _bupc_Tthreads6) == _bupc_comma)
      {
#line 109 "./src/main.c"
        _bupc_Mptra82 = UPCR_ADD_PSHARED1(data_cpy, 8ULL, i);
#line 109 "./src/main.c"
        _bupc_Mptra80 = UPCR_ADD_PSHARED1(data, 8ULL, i);
#line 109 "./src/main.c"
        _bupc_spillld81 = UPCR_GET_PSHARED_DOUBLEVAL(_bupc_Mptra80, 0);
#line 109 "./src/main.c"
        UPCR_PUT_PSHARED(_bupc_Mptra82, 0, &_bupc_spillld81, 8);
#line 110 "./src/main.c"
        _bupc_Mptra85 = UPCR_ADD_PSHARED1(data_cpy, 8ULL, i + (((int) upcr_threads () ) * 256));
#line 110 "./src/main.c"
        _bupc_Mptra83 = UPCR_ADD_PSHARED1(data, 8ULL, i + (((int) upcr_threads () ) * 256));
#line 110 "./src/main.c"
        _bupc_spillld84 = UPCR_GET_PSHARED_DOUBLEVAL(_bupc_Mptra83, 0);
#line 110 "./src/main.c"
        UPCR_PUT_PSHARED(_bupc_Mptra85, 0, &_bupc_spillld84, 8);
      }
#line 111 "./src/main.c"
      _1 :;
#line 111 "./src/main.c"
      i = i + 1;
    }
#line 107 "./src/main.c"
    (*((_INT32 *) UPCR_TLD_ADDR( upcr_forall_control ))) = 0;
  }
#line 112 "./src/main.c"
  bit_reversal_copy();
#line 113 "./src/main.c"
  if(((int) upcr_mythread () ) == 0)
#line 113 "./src/main.c"
  {
#line 119 "./src/main.c"
    s = 1;
#line 119 "./src/main.c"
    _bupc_comma3 = log2((_IEEE64)(((int) upcr_threads () ) * 256));
#line 119 "./src/main.c"
    _bupc__spilleq7 = _bupc_comma3;
#line 119 "./src/main.c"
    while((_IEEE64)(s) <= _bupc__spilleq7)
#line 119 "./src/main.c"
    {
#line 121 "./src/main.c"
      m = _I4SHL(1, s);
#line 122 "./src/main.c"
      _bupc_comma0 = cos(-6.28318530718 / (_IEEE64)(m));
#line 122 "./src/main.c"
      (omega_m)[0] = _bupc_comma0;
#line 123 "./src/main.c"
      _bupc_comma1 = sin(-6.28318530718 / (_IEEE64)(m));
#line 123 "./src/main.c"
      (omega_m)[1] = _bupc_comma1;
#line 124 "./src/main.c"
      if((*((_INT32 *) UPCR_TLD_ADDR( upcr_forall_control ))))
#line 124 "./src/main.c"
      {
#line 124 "./src/main.c"
        k = 0;
#line 124 "./src/main.c"
        while(k < (((int) upcr_threads () ) * 256))
        {
#line 127 "./src/main.c"
          (omega)[0] = 1.0;
#line 128 "./src/main.c"
          (omega)[1] = 0.0;
#line 129 "./src/main.c"
          j = 0;
#line 129 "./src/main.c"
          while(j < (m / 2))
#line 129 "./src/main.c"
          {
#line 131 "./src/main.c"
            _bupc_Mptra86 = UPCR_ADD_PSHARED1(data_cpy, 8ULL, (k + j) + (m / 2));
#line 131 "./src/main.c"
            _bupc_spillld87 = UPCR_GET_PSHARED_DOUBLEVAL(_bupc_Mptra86, 0);
#line 131 "./src/main.c"
            _bupc_Mptra88 = UPCR_ADD_PSHARED1(data_cpy, 8ULL, ((k + j) + (m / 2)) + (((int) upcr_threads () ) * 256));
#line 131 "./src/main.c"
            _bupc_spillld89 = UPCR_GET_PSHARED_DOUBLEVAL(_bupc_Mptra88, 0);
#line 131 "./src/main.c"
            (t)[0] = ((omega)[0] * _bupc_spillld87) - ((omega)[1] * _bupc_spillld89);
#line 132 "./src/main.c"
            _bupc_Mptra90 = UPCR_ADD_PSHARED1(data_cpy, 8ULL, ((k + j) + (m / 2)) + (((int) upcr_threads () ) * 256));
#line 132 "./src/main.c"
            _bupc_spillld91 = UPCR_GET_PSHARED_DOUBLEVAL(_bupc_Mptra90, 0);
#line 132 "./src/main.c"
            _bupc_Mptra92 = UPCR_ADD_PSHARED1(data_cpy, 8ULL, (k + j) + (m / 2));
#line 132 "./src/main.c"
            _bupc_spillld93 = UPCR_GET_PSHARED_DOUBLEVAL(_bupc_Mptra92, 0);
#line 132 "./src/main.c"
            (t)[1] = ((omega)[0] * _bupc_spillld91) + ((omega)[1] * _bupc_spillld93);
#line 133 "./src/main.c"
            _bupc_Mptra94 = UPCR_ADD_PSHARED1(data_cpy, 8ULL, k + j);
#line 133 "./src/main.c"
            _bupc_spillld95 = UPCR_GET_PSHARED_DOUBLEVAL(_bupc_Mptra94, 0);
#line 133 "./src/main.c"
            (u)[0] = _bupc_spillld95;
#line 134 "./src/main.c"
            _bupc_Mptra96 = UPCR_ADD_PSHARED1(data_cpy, 8ULL, (k + j) + (((int) upcr_threads () ) * 256));
#line 134 "./src/main.c"
            _bupc_spillld97 = UPCR_GET_PSHARED_DOUBLEVAL(_bupc_Mptra96, 0);
#line 134 "./src/main.c"
            (u)[1] = _bupc_spillld97;
#line 136 "./src/main.c"
            upcr_barrier(221775943, 1);
#line 137 "./src/main.c"
            _bupc_Mptra98 = UPCR_ADD_PSHARED1(data_cpy, 8ULL, k + j);
            _bupc_spillstoreparm99 = (u)[0] + (t)[0];
#line 137 "./src/main.c"
            UPCR_PUT_PSHARED(_bupc_Mptra98, 0, &_bupc_spillstoreparm99, 8);
#line 138 "./src/main.c"
            _bupc_Mptra100 = UPCR_ADD_PSHARED1(data_cpy, 8ULL, (k + j) + (((int) upcr_threads () ) * 256));
            _bupc_spillstoreparm101 = (u)[1] + (t)[1];
#line 138 "./src/main.c"
            UPCR_PUT_PSHARED(_bupc_Mptra100, 0, &_bupc_spillstoreparm101, 8);
#line 139 "./src/main.c"
            _bupc_Mptra102 = UPCR_ADD_PSHARED1(data_cpy, 8ULL, (k + j) + (m / 2));
            _bupc_spillstoreparm103 = (u)[0] - (t)[0];
#line 139 "./src/main.c"
            UPCR_PUT_PSHARED(_bupc_Mptra102, 0, &_bupc_spillstoreparm103, 8);
#line 140 "./src/main.c"
            _bupc_Mptra104 = UPCR_ADD_PSHARED1(data_cpy, 8ULL, ((k + j) + (m / 2)) + (((int) upcr_threads () ) * 256));
            _bupc_spillstoreparm105 = (u)[1] - (t)[1];
#line 140 "./src/main.c"
            UPCR_PUT_PSHARED(_bupc_Mptra104, 0, &_bupc_spillstoreparm105, 8);
#line 142 "./src/main.c"
            upcr_barrier(221775944, 1);
#line 143 "./src/main.c"
            (tmp)[0] = ((omega)[0] * (omega_m)[0]) - ((omega)[1] * (omega_m)[1]);
#line 144 "./src/main.c"
            (tmp)[1] = ((omega)[1] * (omega_m)[0]) + ((omega)[0] * (omega_m)[1]);
#line 145 "./src/main.c"
            (omega)[0] = (tmp)[0];
#line 146 "./src/main.c"
            (omega)[1] = (tmp)[1];
#line 147 "./src/main.c"
            _25 :;
#line 147 "./src/main.c"
            j = j + 1;
          }
#line 148 "./src/main.c"
          upcr_barrier(221775945, 1);
#line 149 "./src/main.c"
          _26 :;
#line 149 "./src/main.c"
          k = k + m;
        }
      }
      else
#line 124 "./src/main.c"
      {
#line 124 "./src/main.c"
        (*((_INT32 *) UPCR_TLD_ADDR( upcr_forall_control ))) = 1;
#line 124 "./src/main.c"
        k = 0;
#line 124 "./src/main.c"
        while(k < (((int) upcr_threads () ) * 256))
#line 124 "./src/main.c"
        {
          _bupc_Tthreads8 = upcr_threads();
          _bupc_comma2 = upcr_mythread();
          if((k % _bupc_Tthreads8) == _bupc_comma2)
          {
#line 127 "./src/main.c"
            (omega)[0] = 1.0;
#line 128 "./src/main.c"
            (omega)[1] = 0.0;
#line 129 "./src/main.c"
            j = 0;
#line 129 "./src/main.c"
            while(j < (m / 2))
#line 129 "./src/main.c"
            {
#line 131 "./src/main.c"
              _bupc_Mptra106 = UPCR_ADD_PSHARED1(data_cpy, 8ULL, (k + j) + (m / 2));
#line 131 "./src/main.c"
              _bupc_spillld107 = UPCR_GET_PSHARED_DOUBLEVAL(_bupc_Mptra106, 0);
#line 131 "./src/main.c"
              _bupc_Mptra108 = UPCR_ADD_PSHARED1(data_cpy, 8ULL, ((k + j) + (m / 2)) + (((int) upcr_threads () ) * 256));
#line 131 "./src/main.c"
              _bupc_spillld109 = UPCR_GET_PSHARED_DOUBLEVAL(_bupc_Mptra108, 0);
#line 131 "./src/main.c"
              (t)[0] = ((omega)[0] * _bupc_spillld107) - ((omega)[1] * _bupc_spillld109);
#line 132 "./src/main.c"
              _bupc_Mptra110 = UPCR_ADD_PSHARED1(data_cpy, 8ULL, ((k + j) + (m / 2)) + (((int) upcr_threads () ) * 256));
#line 132 "./src/main.c"
              _bupc_spillld111 = UPCR_GET_PSHARED_DOUBLEVAL(_bupc_Mptra110, 0);
#line 132 "./src/main.c"
              _bupc_Mptra112 = UPCR_ADD_PSHARED1(data_cpy, 8ULL, (k + j) + (m / 2));
#line 132 "./src/main.c"
              _bupc_spillld113 = UPCR_GET_PSHARED_DOUBLEVAL(_bupc_Mptra112, 0);
#line 132 "./src/main.c"
              (t)[1] = ((omega)[0] * _bupc_spillld111) + ((omega)[1] * _bupc_spillld113);
#line 133 "./src/main.c"
              _bupc_Mptra114 = UPCR_ADD_PSHARED1(data_cpy, 8ULL, k + j);
#line 133 "./src/main.c"
              _bupc_spillld115 = UPCR_GET_PSHARED_DOUBLEVAL(_bupc_Mptra114, 0);
#line 133 "./src/main.c"
              (u)[0] = _bupc_spillld115;
#line 134 "./src/main.c"
              _bupc_Mptra116 = UPCR_ADD_PSHARED1(data_cpy, 8ULL, (k + j) + (((int) upcr_threads () ) * 256));
#line 134 "./src/main.c"
              _bupc_spillld117 = UPCR_GET_PSHARED_DOUBLEVAL(_bupc_Mptra116, 0);
#line 134 "./src/main.c"
              (u)[1] = _bupc_spillld117;
#line 136 "./src/main.c"
              upcr_barrier(221775943, 1);
#line 137 "./src/main.c"
              _bupc_Mptra118 = UPCR_ADD_PSHARED1(data_cpy, 8ULL, k + j);
              _bupc_spillstoreparm119 = (u)[0] + (t)[0];
#line 137 "./src/main.c"
              UPCR_PUT_PSHARED(_bupc_Mptra118, 0, &_bupc_spillstoreparm119, 8);
#line 138 "./src/main.c"
              _bupc_Mptra120 = UPCR_ADD_PSHARED1(data_cpy, 8ULL, (k + j) + (((int) upcr_threads () ) * 256));
              _bupc_spillstoreparm121 = (u)[1] + (t)[1];
#line 138 "./src/main.c"
              UPCR_PUT_PSHARED(_bupc_Mptra120, 0, &_bupc_spillstoreparm121, 8);
#line 139 "./src/main.c"
              _bupc_Mptra122 = UPCR_ADD_PSHARED1(data_cpy, 8ULL, (k + j) + (m / 2));
              _bupc_spillstoreparm123 = (u)[0] - (t)[0];
#line 139 "./src/main.c"
              UPCR_PUT_PSHARED(_bupc_Mptra122, 0, &_bupc_spillstoreparm123, 8);
#line 140 "./src/main.c"
              _bupc_Mptra124 = UPCR_ADD_PSHARED1(data_cpy, 8ULL, ((k + j) + (m / 2)) + (((int) upcr_threads () ) * 256));
              _bupc_spillstoreparm125 = (u)[1] - (t)[1];
#line 140 "./src/main.c"
              UPCR_PUT_PSHARED(_bupc_Mptra124, 0, &_bupc_spillstoreparm125, 8);
#line 142 "./src/main.c"
              upcr_barrier(221775944, 1);
#line 143 "./src/main.c"
              (tmp)[0] = ((omega)[0] * (omega_m)[0]) - ((omega)[1] * (omega_m)[1]);
#line 144 "./src/main.c"
              (tmp)[1] = ((omega)[1] * (omega_m)[0]) + ((omega)[0] * (omega_m)[1]);
#line 145 "./src/main.c"
              (omega)[0] = (tmp)[0];
#line 146 "./src/main.c"
              (omega)[1] = (tmp)[1];
#line 147 "./src/main.c"
              _4 :;
#line 147 "./src/main.c"
              j = j + 1;
            }
#line 148 "./src/main.c"
            upcr_barrier(221775945, 1);
          }
#line 149 "./src/main.c"
          _3 :;
#line 149 "./src/main.c"
          k = k + m;
        }
#line 124 "./src/main.c"
        (*((_INT32 *) UPCR_TLD_ADDR( upcr_forall_control ))) = 0;
      }
#line 150 "./src/main.c"
      _2 :;
#line 150 "./src/main.c"
      s = s + 1;
#line 119 "./src/main.c"
      _bupc_comma3 = log2((_IEEE64)(((int) upcr_threads () ) * 256));
#line 119 "./src/main.c"
      _bupc__spilleq7 = _bupc_comma3;
    }
  }
#line 151 "./src/main.c"
  upcr_barrier(221775946, 1);
#line 153 "./src/main.c"
  if((*((_INT32 *) UPCR_TLD_ADDR( upcr_forall_control ))))
#line 153 "./src/main.c"
  {
#line 153 "./src/main.c"
    _bupc_w2c_i0 = 0;
#line 153 "./src/main.c"
    while(_bupc_w2c_i0 < (((int) upcr_threads () ) * 256))
    {
#line 155 "./src/main.c"
      _bupc_Mptra128 = UPCR_ADD_PSHARED1(data, 8ULL, _bupc_w2c_i0);
#line 155 "./src/main.c"
      _bupc_Mptra126 = UPCR_ADD_PSHARED1(data_cpy, 8ULL, _bupc_w2c_i0);
#line 155 "./src/main.c"
      _bupc_spillld127 = UPCR_GET_PSHARED_DOUBLEVAL(_bupc_Mptra126, 0);
#line 155 "./src/main.c"
      UPCR_PUT_PSHARED(_bupc_Mptra128, 0, &_bupc_spillld127, 8);
#line 156 "./src/main.c"
      _bupc_Mptra131 = UPCR_ADD_PSHARED1(data, 8ULL, _bupc_w2c_i0 + (((int) upcr_threads () ) * 256));
#line 156 "./src/main.c"
      _bupc_Mptra129 = UPCR_ADD_PSHARED1(data_cpy, 8ULL, _bupc_w2c_i0 + (((int) upcr_threads () ) * 256));
#line 156 "./src/main.c"
      _bupc_spillld130 = UPCR_GET_PSHARED_DOUBLEVAL(_bupc_Mptra129, 0);
#line 156 "./src/main.c"
      UPCR_PUT_PSHARED(_bupc_Mptra131, 0, &_bupc_spillld130, 8);
#line 157 "./src/main.c"
      _27 :;
#line 157 "./src/main.c"
      _bupc_w2c_i0 = _bupc_w2c_i0 + 1;
    }
  }
  else
#line 153 "./src/main.c"
  {
#line 153 "./src/main.c"
    (*((_INT32 *) UPCR_TLD_ADDR( upcr_forall_control ))) = 1;
#line 153 "./src/main.c"
    _bupc_w2c_i0 = 0;
#line 153 "./src/main.c"
    while(_bupc_w2c_i0 < (((int) upcr_threads () ) * 256))
#line 153 "./src/main.c"
    {
      _bupc_Tthreads9 = upcr_threads();
      _bupc_comma4 = upcr_mythread();
      if((_bupc_w2c_i0 % _bupc_Tthreads9) == _bupc_comma4)
      {
#line 155 "./src/main.c"
        _bupc_Mptra134 = UPCR_ADD_PSHARED1(data, 8ULL, _bupc_w2c_i0);
#line 155 "./src/main.c"
        _bupc_Mptra132 = UPCR_ADD_PSHARED1(data_cpy, 8ULL, _bupc_w2c_i0);
#line 155 "./src/main.c"
        _bupc_spillld133 = UPCR_GET_PSHARED_DOUBLEVAL(_bupc_Mptra132, 0);
#line 155 "./src/main.c"
        UPCR_PUT_PSHARED(_bupc_Mptra134, 0, &_bupc_spillld133, 8);
#line 156 "./src/main.c"
        _bupc_Mptra137 = UPCR_ADD_PSHARED1(data, 8ULL, _bupc_w2c_i0 + (((int) upcr_threads () ) * 256));
#line 156 "./src/main.c"
        _bupc_Mptra135 = UPCR_ADD_PSHARED1(data_cpy, 8ULL, _bupc_w2c_i0 + (((int) upcr_threads () ) * 256));
#line 156 "./src/main.c"
        _bupc_spillld136 = UPCR_GET_PSHARED_DOUBLEVAL(_bupc_Mptra135, 0);
#line 156 "./src/main.c"
        UPCR_PUT_PSHARED(_bupc_Mptra137, 0, &_bupc_spillld136, 8);
      }
#line 157 "./src/main.c"
      _5 :;
#line 157 "./src/main.c"
      _bupc_w2c_i0 = _bupc_w2c_i0 + 1;
    }
#line 153 "./src/main.c"
    (*((_INT32 *) UPCR_TLD_ADDR( upcr_forall_control ))) = 0;
  }
  UPCR_EXIT_FUNCTION();
  return;
} /* fft */


#line 161 "./src/main.c"
extern void fft_reverse()
#line 161 "./src/main.c"
{
#line 161 "./src/main.c"
  UPCR_BEGIN_FUNCTION();
  register _INT32 _bupc_comma;
  register _INT32 _bupc_comma0;
  int i;
  _INT32 _bupc_Tthreads10;
  _INT32 _bupc_Tthreads11;
  upcr_pshared_ptr_t _bupc_Mptra138;
  _IEEE64 _bupc_spillld139;
  upcr_pshared_ptr_t _bupc_Mptra140;
  _IEEE64 _bupc_spillstoreparm141;
  upcr_pshared_ptr_t _bupc_Mptra142;
  _IEEE64 _bupc_spillld143;
  upcr_pshared_ptr_t _bupc_Mptra144;
  _IEEE64 _bupc_spillstoreparm145;
  upcr_pshared_ptr_t _bupc_Mptra146;
  _IEEE64 _bupc_spillld147;
  upcr_pshared_ptr_t _bupc_Mptra148;
  _IEEE64 _bupc_spillstoreparm149;
  upcr_pshared_ptr_t _bupc_Mptra150;
  _IEEE64 _bupc_spillld151;
  upcr_pshared_ptr_t _bupc_Mptra152;
  _IEEE64 _bupc_spillstoreparm153;
  upcr_pshared_ptr_t _bupc_Mptra154;
  _IEEE64 _bupc_spillld155;
  upcr_pshared_ptr_t _bupc_Mptra156;
  _IEEE64 _bupc_spillstoreparm157;
  upcr_pshared_ptr_t _bupc_Mptra158;
  _IEEE64 _bupc_spillld159;
  upcr_pshared_ptr_t _bupc_Mptra160;
  _IEEE64 _bupc_spillstoreparm161;
  
#line 163 "./src/main.c"
  if((*((_INT32 *) UPCR_TLD_ADDR( upcr_forall_control ))))
#line 163 "./src/main.c"
  {
#line 163 "./src/main.c"
    i = 0;
#line 163 "./src/main.c"
    while(i < (((int) upcr_threads () ) * 256))
    {
#line 165 "./src/main.c"
      _bupc_Mptra140 = UPCR_ADD_PSHARED1(data, 8ULL, i + (((int) upcr_threads () ) * 256));
#line 165 "./src/main.c"
      _bupc_Mptra138 = UPCR_ADD_PSHARED1(data, 8ULL, i + (((int) upcr_threads () ) * 256));
#line 165 "./src/main.c"
      _bupc_spillld139 = UPCR_GET_PSHARED_DOUBLEVAL(_bupc_Mptra138, 0);
      _bupc_spillstoreparm141 = -_bupc_spillld139;
#line 165 "./src/main.c"
      UPCR_PUT_PSHARED(_bupc_Mptra140, 0, &_bupc_spillstoreparm141, 8);
#line 166 "./src/main.c"
      _11 :;
#line 166 "./src/main.c"
      i = i + 1;
    }
  }
  else
#line 163 "./src/main.c"
  {
#line 163 "./src/main.c"
    (*((_INT32 *) UPCR_TLD_ADDR( upcr_forall_control ))) = 1;
#line 163 "./src/main.c"
    i = 0;
#line 163 "./src/main.c"
    while(i < (((int) upcr_threads () ) * 256))
#line 163 "./src/main.c"
    {
      _bupc_Tthreads10 = upcr_threads();
      _bupc_comma = upcr_mythread();
      if((i % _bupc_Tthreads10) == _bupc_comma)
      {
#line 165 "./src/main.c"
        _bupc_Mptra144 = UPCR_ADD_PSHARED1(data, 8ULL, i + (((int) upcr_threads () ) * 256));
#line 165 "./src/main.c"
        _bupc_Mptra142 = UPCR_ADD_PSHARED1(data, 8ULL, i + (((int) upcr_threads () ) * 256));
#line 165 "./src/main.c"
        _bupc_spillld143 = UPCR_GET_PSHARED_DOUBLEVAL(_bupc_Mptra142, 0);
        _bupc_spillstoreparm145 = -_bupc_spillld143;
#line 165 "./src/main.c"
        UPCR_PUT_PSHARED(_bupc_Mptra144, 0, &_bupc_spillstoreparm145, 8);
      }
#line 166 "./src/main.c"
      _1 :;
#line 166 "./src/main.c"
      i = i + 1;
    }
#line 163 "./src/main.c"
    (*((_INT32 *) UPCR_TLD_ADDR( upcr_forall_control ))) = 0;
  }
#line 167 "./src/main.c"
  upcr_barrier(221775947, 1);
#line 168 "./src/main.c"
  fft();
#line 169 "./src/main.c"
  if((*((_INT32 *) UPCR_TLD_ADDR( upcr_forall_control ))))
#line 169 "./src/main.c"
  {
#line 169 "./src/main.c"
    i = 0;
#line 169 "./src/main.c"
    while(i < (((int) upcr_threads () ) * 256))
    {
#line 171 "./src/main.c"
      _bupc_Mptra148 = UPCR_ADD_PSHARED1(data, 8ULL, i);
#line 171 "./src/main.c"
      _bupc_Mptra146 = UPCR_ADD_PSHARED1(data, 8ULL, i);
#line 171 "./src/main.c"
      _bupc_spillld147 = UPCR_GET_PSHARED_DOUBLEVAL(_bupc_Mptra146, 0);
      _bupc_spillstoreparm149 = _bupc_spillld147 / (_IEEE64)((((int) upcr_threads () ) * 256));
#line 171 "./src/main.c"
      UPCR_PUT_PSHARED(_bupc_Mptra148, 0, &_bupc_spillstoreparm149, 8);
#line 172 "./src/main.c"
      _bupc_Mptra152 = UPCR_ADD_PSHARED1(data, 8ULL, i + (((int) upcr_threads () ) * 256));
#line 172 "./src/main.c"
      _bupc_Mptra150 = UPCR_ADD_PSHARED1(data, 8ULL, i + (((int) upcr_threads () ) * 256));
#line 172 "./src/main.c"
      _bupc_spillld151 = UPCR_GET_PSHARED_DOUBLEVAL(_bupc_Mptra150, 0);
      _bupc_spillstoreparm153 = (-_bupc_spillld151) / (_IEEE64)((((int) upcr_threads () ) * 256));
#line 172 "./src/main.c"
      UPCR_PUT_PSHARED(_bupc_Mptra152, 0, &_bupc_spillstoreparm153, 8);
#line 173 "./src/main.c"
      _12 :;
#line 173 "./src/main.c"
      i = i + 1;
    }
  }
  else
#line 169 "./src/main.c"
  {
#line 169 "./src/main.c"
    (*((_INT32 *) UPCR_TLD_ADDR( upcr_forall_control ))) = 1;
#line 169 "./src/main.c"
    i = 0;
#line 169 "./src/main.c"
    while(i < (((int) upcr_threads () ) * 256))
#line 169 "./src/main.c"
    {
      _bupc_Tthreads11 = upcr_threads();
      _bupc_comma0 = upcr_mythread();
      if((i % _bupc_Tthreads11) == _bupc_comma0)
      {
#line 171 "./src/main.c"
        _bupc_Mptra156 = UPCR_ADD_PSHARED1(data, 8ULL, i);
#line 171 "./src/main.c"
        _bupc_Mptra154 = UPCR_ADD_PSHARED1(data, 8ULL, i);
#line 171 "./src/main.c"
        _bupc_spillld155 = UPCR_GET_PSHARED_DOUBLEVAL(_bupc_Mptra154, 0);
        _bupc_spillstoreparm157 = _bupc_spillld155 / (_IEEE64)((((int) upcr_threads () ) * 256));
#line 171 "./src/main.c"
        UPCR_PUT_PSHARED(_bupc_Mptra156, 0, &_bupc_spillstoreparm157, 8);
#line 172 "./src/main.c"
        _bupc_Mptra160 = UPCR_ADD_PSHARED1(data, 8ULL, i + (((int) upcr_threads () ) * 256));
#line 172 "./src/main.c"
        _bupc_Mptra158 = UPCR_ADD_PSHARED1(data, 8ULL, i + (((int) upcr_threads () ) * 256));
#line 172 "./src/main.c"
        _bupc_spillld159 = UPCR_GET_PSHARED_DOUBLEVAL(_bupc_Mptra158, 0);
        _bupc_spillstoreparm161 = (-_bupc_spillld159) / (_IEEE64)((((int) upcr_threads () ) * 256));
#line 172 "./src/main.c"
        UPCR_PUT_PSHARED(_bupc_Mptra160, 0, &_bupc_spillstoreparm161, 8);
      }
#line 173 "./src/main.c"
      _2 :;
#line 173 "./src/main.c"
      i = i + 1;
    }
#line 169 "./src/main.c"
    (*((_INT32 *) UPCR_TLD_ADDR( upcr_forall_control ))) = 0;
  }
  UPCR_EXIT_FUNCTION();
  return;
} /* fft_reverse */


#line 177 "./src/main.c"
extern int bit_reverse(
  int num)
#line 177 "./src/main.c"
{
#line 177 "./src/main.c"
  UPCR_BEGIN_FUNCTION();
  register _IEEE64 _bupc_comma;
  int N_bits;
  int num_rev;
  int i;
  int curr_bit;
  
#line 178 "./src/main.c"
  _bupc_comma = log2((_IEEE64)(((int) upcr_threads () ) * 256));
#line 178 "./src/main.c"
  N_bits = _I4F8TRUNC(_bupc_comma);
#line 180 "./src/main.c"
  num_rev = 0;
#line 181 "./src/main.c"
  i = 0;
#line 181 "./src/main.c"
  while(i < N_bits)
#line 181 "./src/main.c"
  {
#line 183 "./src/main.c"
    curr_bit = _I4ASHR(num, i) & 1;
#line 184 "./src/main.c"
    num_rev = num_rev + _I4SHL(curr_bit, (N_bits - i) + -1);
#line 185 "./src/main.c"
    _1 :;
#line 185 "./src/main.c"
    i = i + 1;
  }
#line 186 "./src/main.c"
  UPCR_EXIT_FUNCTION();
#line 186 "./src/main.c"
  return num_rev;
} /* bit_reverse */


#line 190 "./src/main.c"
extern void bit_reversal_copy()
#line 190 "./src/main.c"
{
#line 190 "./src/main.c"
  UPCR_BEGIN_FUNCTION();
  register _INT32 _bupc_comma;
  register _INT32 _bupc_comma0;
  register _INT32 _bupc_comma1;
  int i;
  _INT32 _bupc_Tthreads12;
  int i_rev;
  int _bupc_w2c_i0;
  _INT32 _bupc_Tthreads13;
  upcr_pshared_ptr_t _bupc_Mptra162;
  _IEEE64 _bupc_spillld163;
  upcr_pshared_ptr_t _bupc_Mptra164;
  upcr_pshared_ptr_t _bupc_Mptra165;
  _IEEE64 _bupc_spillld166;
  upcr_pshared_ptr_t _bupc_Mptra167;
  upcr_pshared_ptr_t _bupc_Mptra168;
  _IEEE64 _bupc_spillld169;
  upcr_pshared_ptr_t _bupc_Mptra170;
  upcr_pshared_ptr_t _bupc_Mptra171;
  _IEEE64 _bupc_spillld172;
  upcr_pshared_ptr_t _bupc_Mptra173;
  upcr_pshared_ptr_t _bupc_Mptra174;
  _IEEE64 _bupc_spillld175;
  upcr_pshared_ptr_t _bupc_Mptra176;
  upcr_pshared_ptr_t _bupc_Mptra177;
  _IEEE64 _bupc_spillld178;
  upcr_pshared_ptr_t _bupc_Mptra179;
  upcr_pshared_ptr_t _bupc_Mptra180;
  _IEEE64 _bupc_spillld181;
  upcr_pshared_ptr_t _bupc_Mptra182;
  upcr_pshared_ptr_t _bupc_Mptra183;
  _IEEE64 _bupc_spillld184;
  upcr_pshared_ptr_t _bupc_Mptra185;
  
#line 191 "./src/main.c"
  if((*((_INT32 *) UPCR_TLD_ADDR( upcr_forall_control ))))
#line 191 "./src/main.c"
  {
#line 191 "./src/main.c"
    i = 0;
#line 191 "./src/main.c"
    while(i < (((int) upcr_threads () ) * 256))
    {
#line 193 "./src/main.c"
      _bupc_comma = bit_reverse(i);
#line 193 "./src/main.c"
      i_rev = _bupc_comma;
#line 194 "./src/main.c"
      _bupc_Mptra164 = UPCR_ADD_PSHARED1(data_cpy, 8ULL, i);
#line 194 "./src/main.c"
      _bupc_Mptra162 = UPCR_ADD_PSHARED1(data, 8ULL, i_rev);
#line 194 "./src/main.c"
      _bupc_spillld163 = UPCR_GET_PSHARED_DOUBLEVAL(_bupc_Mptra162, 0);
#line 194 "./src/main.c"
      UPCR_PUT_PSHARED(_bupc_Mptra164, 0, &_bupc_spillld163, 8);
#line 195 "./src/main.c"
      _bupc_Mptra167 = UPCR_ADD_PSHARED1(data_cpy, 8ULL, i + (((int) upcr_threads () ) * 256));
#line 195 "./src/main.c"
      _bupc_Mptra165 = UPCR_ADD_PSHARED1(data, 8ULL, i_rev + (((int) upcr_threads () ) * 256));
#line 195 "./src/main.c"
      _bupc_spillld166 = UPCR_GET_PSHARED_DOUBLEVAL(_bupc_Mptra165, 0);
#line 195 "./src/main.c"
      UPCR_PUT_PSHARED(_bupc_Mptra167, 0, &_bupc_spillld166, 8);
#line 196 "./src/main.c"
      _11 :;
#line 196 "./src/main.c"
      i = i + 1;
    }
  }
  else
#line 191 "./src/main.c"
  {
#line 191 "./src/main.c"
    (*((_INT32 *) UPCR_TLD_ADDR( upcr_forall_control ))) = 1;
#line 191 "./src/main.c"
    i = 0;
#line 191 "./src/main.c"
    while(i < (((int) upcr_threads () ) * 256))
#line 191 "./src/main.c"
    {
      _bupc_Tthreads12 = upcr_threads();
      _bupc_comma0 = upcr_mythread();
      if((i % _bupc_Tthreads12) == _bupc_comma0)
      {
#line 193 "./src/main.c"
        _bupc_comma = bit_reverse(i);
#line 193 "./src/main.c"
        i_rev = _bupc_comma;
#line 194 "./src/main.c"
        _bupc_Mptra170 = UPCR_ADD_PSHARED1(data_cpy, 8ULL, i);
#line 194 "./src/main.c"
        _bupc_Mptra168 = UPCR_ADD_PSHARED1(data, 8ULL, i_rev);
#line 194 "./src/main.c"
        _bupc_spillld169 = UPCR_GET_PSHARED_DOUBLEVAL(_bupc_Mptra168, 0);
#line 194 "./src/main.c"
        UPCR_PUT_PSHARED(_bupc_Mptra170, 0, &_bupc_spillld169, 8);
#line 195 "./src/main.c"
        _bupc_Mptra173 = UPCR_ADD_PSHARED1(data_cpy, 8ULL, i + (((int) upcr_threads () ) * 256));
#line 195 "./src/main.c"
        _bupc_Mptra171 = UPCR_ADD_PSHARED1(data, 8ULL, i_rev + (((int) upcr_threads () ) * 256));
#line 195 "./src/main.c"
        _bupc_spillld172 = UPCR_GET_PSHARED_DOUBLEVAL(_bupc_Mptra171, 0);
#line 195 "./src/main.c"
        UPCR_PUT_PSHARED(_bupc_Mptra173, 0, &_bupc_spillld172, 8);
      }
#line 196 "./src/main.c"
      _1 :;
#line 196 "./src/main.c"
      i = i + 1;
    }
#line 191 "./src/main.c"
    (*((_INT32 *) UPCR_TLD_ADDR( upcr_forall_control ))) = 0;
  }
#line 197 "./src/main.c"
  upcr_barrier(221775948, 1);
#line 198 "./src/main.c"
  if((*((_INT32 *) UPCR_TLD_ADDR( upcr_forall_control ))))
#line 198 "./src/main.c"
  {
#line 198 "./src/main.c"
    _bupc_w2c_i0 = 0;
#line 198 "./src/main.c"
    while(_bupc_w2c_i0 < (((int) upcr_threads () ) * 256))
    {
#line 200 "./src/main.c"
      _bupc_Mptra176 = UPCR_ADD_PSHARED1(data, 8ULL, _bupc_w2c_i0);
#line 200 "./src/main.c"
      _bupc_Mptra174 = UPCR_ADD_PSHARED1(data_cpy, 8ULL, _bupc_w2c_i0);
#line 200 "./src/main.c"
      _bupc_spillld175 = UPCR_GET_PSHARED_DOUBLEVAL(_bupc_Mptra174, 0);
#line 200 "./src/main.c"
      UPCR_PUT_PSHARED(_bupc_Mptra176, 0, &_bupc_spillld175, 8);
#line 201 "./src/main.c"
      _bupc_Mptra179 = UPCR_ADD_PSHARED1(data, 8ULL, _bupc_w2c_i0 + (((int) upcr_threads () ) * 256));
#line 201 "./src/main.c"
      _bupc_Mptra177 = UPCR_ADD_PSHARED1(data_cpy, 8ULL, _bupc_w2c_i0 + (((int) upcr_threads () ) * 256));
#line 201 "./src/main.c"
      _bupc_spillld178 = UPCR_GET_PSHARED_DOUBLEVAL(_bupc_Mptra177, 0);
#line 201 "./src/main.c"
      UPCR_PUT_PSHARED(_bupc_Mptra179, 0, &_bupc_spillld178, 8);
#line 202 "./src/main.c"
      _12 :;
#line 202 "./src/main.c"
      _bupc_w2c_i0 = _bupc_w2c_i0 + 1;
    }
  }
  else
#line 198 "./src/main.c"
  {
#line 198 "./src/main.c"
    (*((_INT32 *) UPCR_TLD_ADDR( upcr_forall_control ))) = 1;
#line 198 "./src/main.c"
    _bupc_w2c_i0 = 0;
#line 198 "./src/main.c"
    while(_bupc_w2c_i0 < (((int) upcr_threads () ) * 256))
#line 198 "./src/main.c"
    {
      _bupc_Tthreads13 = upcr_threads();
      _bupc_comma1 = upcr_mythread();
      if((_bupc_w2c_i0 % _bupc_Tthreads13) == _bupc_comma1)
      {
#line 200 "./src/main.c"
        _bupc_Mptra182 = UPCR_ADD_PSHARED1(data, 8ULL, _bupc_w2c_i0);
#line 200 "./src/main.c"
        _bupc_Mptra180 = UPCR_ADD_PSHARED1(data_cpy, 8ULL, _bupc_w2c_i0);
#line 200 "./src/main.c"
        _bupc_spillld181 = UPCR_GET_PSHARED_DOUBLEVAL(_bupc_Mptra180, 0);
#line 200 "./src/main.c"
        UPCR_PUT_PSHARED(_bupc_Mptra182, 0, &_bupc_spillld181, 8);
#line 201 "./src/main.c"
        _bupc_Mptra185 = UPCR_ADD_PSHARED1(data, 8ULL, _bupc_w2c_i0 + (((int) upcr_threads () ) * 256));
#line 201 "./src/main.c"
        _bupc_Mptra183 = UPCR_ADD_PSHARED1(data_cpy, 8ULL, _bupc_w2c_i0 + (((int) upcr_threads () ) * 256));
#line 201 "./src/main.c"
        _bupc_spillld184 = UPCR_GET_PSHARED_DOUBLEVAL(_bupc_Mptra183, 0);
#line 201 "./src/main.c"
        UPCR_PUT_PSHARED(_bupc_Mptra185, 0, &_bupc_spillld184, 8);
      }
#line 202 "./src/main.c"
      _2 :;
#line 202 "./src/main.c"
      _bupc_w2c_i0 = _bupc_w2c_i0 + 1;
    }
#line 198 "./src/main.c"
    (*((_INT32 *) UPCR_TLD_ADDR( upcr_forall_control ))) = 0;
  }
#line 203 "./src/main.c"
  upcr_barrier(221775949, 1);
  UPCR_EXIT_FUNCTION();
  return;
} /* bit_reversal_copy */


#line 207 "./src/main.c"
extern void print_data(
  const char * filename)
#line 207 "./src/main.c"
{
#line 207 "./src/main.c"
  UPCR_BEGIN_FUNCTION();
  struct _IO_FILE * f;
  int i;
  struct _IO_FILE * _bupc_call186;
  upcr_pshared_ptr_t _bupc_Mptra187;
  _IEEE64 _bupc_spillld188;
  upcr_pshared_ptr_t _bupc_Mptra189;
  _IEEE64 _bupc_spillld190;
  
#line 208 "./src/main.c"
  if(((int) upcr_mythread () ) == 0)
#line 208 "./src/main.c"
  {
#line 210 "./src/main.c"
    _bupc_call186 = fopen(filename, "w");
#line 210 "./src/main.c"
    f = _bupc_call186;
#line 211 "./src/main.c"
    i = 0;
#line 211 "./src/main.c"
    while(i < (((int) upcr_threads () ) * 256))
#line 211 "./src/main.c"
    {
#line 213 "./src/main.c"
      _bupc_Mptra187 = UPCR_ADD_PSHARED1(data, 8ULL, i);
#line 213 "./src/main.c"
      _bupc_spillld188 = UPCR_GET_PSHARED_DOUBLEVAL(_bupc_Mptra187, 0);
#line 213 "./src/main.c"
      _bupc_Mptra189 = UPCR_ADD_PSHARED1(data, 8ULL, i + (((int) upcr_threads () ) * 256));
#line 213 "./src/main.c"
      _bupc_spillld190 = UPCR_GET_PSHARED_DOUBLEVAL(_bupc_Mptra189, 0);
#line 213 "./src/main.c"
      fprintf(f, "%d,\t%lf,\t%lf\n", i, _bupc_spillld188, _bupc_spillld190);
#line 214 "./src/main.c"
      _1 :;
#line 214 "./src/main.c"
      i = i + 1;
    }
#line 215 "./src/main.c"
    fclose(f);
  }
  UPCR_EXIT_FUNCTION();
  return;
} /* print_data */

#line 1 "_SYSTEM"
/**************************************************************************/
/* upcc-generated strings for configuration consistency checks            */

GASNETT_IDENT(UPCRI_IdentString_main_o_1655810623_GASNetConfig_gen, 
 "$GASNetConfig: (/tmp/upcc--553549-1655810623/main.trans.c) RELEASE=2022.3.0,SPEC=0.15,CONDUIT=MPI(MPI-2.9/REFERENCE-2022.3),THREADMODEL=PAR,SEGMENT=FAST,PTR=64bit,CACHE_LINE_BYTES=64,noalign,pshm,nodebug,notrace,nostats,nodebugmalloc,nosrclines,timers_native,membars_native,atomics_native,atomic32_native,atomic64_native,notiopt $");
GASNETT_IDENT(UPCRI_IdentString_main_o_1655810623_UPCRConfig_gen,
 "$UPCRConfig: (/tmp/upcc--553549-1655810623/main.trans.c) VERSION=2022.5.0,PLATFORMENV=shared-distributed,SHMEM=pthreads/pshm,SHAREDPTRREP=packed/p20:t10:a34,TRANS=berkeleyupc,nodebug,nogasp,dynamicthreads $");
GASNETT_IDENT(UPCRI_IdentString_main_o_1655810623_translatetime, 
 "$UPCTranslateTime: (main.o) Tue Jun 21 04:23:43 2022 $");
GASNETT_IDENT(UPCRI_IdentString_main_o_1655810623_GASNetConfig_obj, 
 "$GASNetConfig: (main.o) " GASNET_CONFIG_STRING " $");
GASNETT_IDENT(UPCRI_IdentString_main_o_1655810623_UPCRConfig_obj,
 "$UPCRConfig: (main.o) " UPCR_CONFIG_STRING UPCRI_THREADCONFIG_STR " $");
GASNETT_IDENT(UPCRI_IdentString_main_o_1655810623_translator, 
 "$UPCTranslator: (main.o) /usr/local/upc/2020.12.0/translator/install/targ (aphid.lbl.gov) $");
GASNETT_IDENT(UPCRI_IdentString_main_o_1655810623_upcver, 
 "$UPCVersion: (main.o) 2020.12.0 $");
GASNETT_IDENT(UPCRI_IdentString_main_o_1655810623_compileline, 
 "$UPCCompileLine: (main.o) /usr/local/upc/2020.12.0/runtime/inst/bin/upcc.pl --at-remote-http -translator=/usr/local/upc/2020.12.0/translator/install/targ --arch-size=64 --network=mpi --pthreads 4 --lines --trans --sizes-file=upcc-sizes main.i $");
GASNETT_IDENT(UPCRI_IdentString_main_o_1655810623_compiletime, 
 "$UPCCompileTime: (main.o) " __DATE__ " " __TIME__ " $");
#ifndef UPCRI_CC /* ensure backward compatilibity for http netcompile */
#define UPCRI_CC <unknown>
#endif
GASNETT_IDENT(UPCRI_IdentString_main_o_1655810623_backendcompiler, 
 "$UPCRBackendCompiler: (main.o) " _STRINGIFY(UPCRI_CC) " $");

#ifdef GASNETT_CONFIGURE_MISMATCH
  GASNETT_IDENT(UPCRI_IdentString_main_o_1655810623_configuremismatch, 
   "$UPCRConfigureMismatch: (main.o) 1 $");
  GASNETT_IDENT(UPCRI_IdentString_main_o_1655810623_configuredcompiler, 
   "$UPCRConfigureCompiler: (main.o) " GASNETT_PLATFORM_COMPILER_IDSTR " $");
  GASNETT_IDENT(UPCRI_IdentString_main_o_1655810623_buildcompiler, 
   "$UPCRBuildCompiler: (main.o) " PLATFORM_COMPILER_IDSTR " $");
#endif

/**************************************************************************/
GASNETT_IDENT(UPCRI_IdentString_main_o_1655810623_transver_2,
 "$UPCTranslatorVersion: (main.o) 2.28.2, built on Dec 11 2020 at 14:19:36, host aphid.lbl.gov linux-x86_64/64, gcc v9.3.0 $");
GASNETT_IDENT(UPCRI_IdentString_main_o_1655810623_shareddata_data,
 "$UPCRStaticSharedData: (data) 8 512 1 8 A512H_R1_d $");
GASNETT_IDENT(UPCRI_IdentString_main_o_1655810623_shareddata_data_cpy,
 "$UPCRStaticSharedData: (data_cpy) 8 512 1 8 A512H_R1_d $");
GASNETT_IDENT(UPCRI_IdentString_INIT_main_6953773828161,"$UPCRInitFn: (main.trans.c) UPCRI_INIT_main_6953773828161 $");
GASNETT_IDENT(UPCRI_IdentString_ALLOC_main_6953773828161,"$UPCRAllocFn: (main.trans.c) UPCRI_ALLOC_main_6953773828161 $");
