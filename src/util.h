#ifndef UTIL_H
#define UTIL_H

/* GCC visibility */
#if defined(__GNUC__) && __GNUC__ >= 4
#define API_EXPORT __attribute__ ((visibility("default")))
#else
#define API_EXPORT
#endif

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif

#endif /* UTIL_H */
