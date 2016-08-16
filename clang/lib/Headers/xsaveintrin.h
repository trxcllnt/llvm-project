/*===---- xsaveintrin.h - XSAVE intrinsic ------------------------------------===
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 *===-----------------------------------------------------------------------===
 */

#ifndef __IMMINTRIN_H
#error "Never use <xsaveintrin.h> directly; include <immintrin.h> instead."
#endif

#ifndef __XSAVEINTRIN_H
#define __XSAVEINTRIN_H

#define _XCR_XFEATURE_ENABLED_MASK 0

/* Define the default attributes for the functions in this file. */
#define __DEFAULT_FN_ATTRS __attribute__((__always_inline__, __nodebug__,  __target__("xsave")))

static __inline__ void __DEFAULT_FN_ATTRS
_xsave(void *__p, unsigned long long __m) {
  return __builtin_ia32_xsave(__p, __m);
}

static __inline__ void __DEFAULT_FN_ATTRS
_xrstor(void *__p, unsigned long long __m) {
  return __builtin_ia32_xrstor(__p, __m);
}

static __inline__ unsigned long long __DEFAULT_FN_ATTRS
_xgetbv(unsigned int __a) {
  return  __builtin_ia32_xgetbv(__a);
}

static __inline__ void __DEFAULT_FN_ATTRS
_xsetbv(unsigned int __a, unsigned long long __b) {
  __builtin_ia32_xsetbv(__a, __b);
}

#ifdef __x86_64__
static __inline__ void __DEFAULT_FN_ATTRS
_xsave64(void *__p, unsigned long long __m) {
  return __builtin_ia32_xsave64(__p, __m);
}

static __inline__ void __DEFAULT_FN_ATTRS
_xrstor64(void *__p, unsigned long long __m) {
  return __builtin_ia32_xrstor64(__p, __m);
}

#endif

#undef __DEFAULT_FN_ATTRS

#endif
