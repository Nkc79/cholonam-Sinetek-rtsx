#ifndef SINETEK_RTSX_COMPAT_OPENBSD_SPL_H
#define SINETEK_RTSX_COMPAT_OPENBSD_SPL_H

#include <sys/cdefs.h> // __BEGIN_DECLS, __END_DECLS

typedef unsigned spl_t;

#if RTSX_DEBUG_OPENBSD_COMPAT_SPL
#define RTSX_OPENBSD_COMPAT_SPL_DBG(...) printf(__VA_ARGS__)
#else
#define RTSX_OPENBSD_COMPAT_SPL_DBG(...) do {} while (0)
#endif

#define splbio() \
({ \
	RTSX_OPENBSD_COMPAT_SPL_DBG("splbio called from %s (line %d)", __FILE__, __LINE__); \
	Sinetek_rtsx_openbsd_compat_splbio(); \
})
#define splhigh() \
({ \
	RTSX_OPENBSD_COMPAT_SPL_DBG("splhigh called from %s (line %d)", __FILE__, __LINE__); \
	Sinetek_rtsx_openbsd_compat_splhigh(); \
})
#define splx(v) \
({ \
	Sinetek_rtsx_openbsd_compat_splx(v); \
	RTSX_OPENBSD_COMPAT_SPL_DBG("splx called from %s (line %d)", __FILE__, __LINE__); \
})

__BEGIN_DECLS

// to be called only by openbsd_compat_tsleep.cpp
void *Sinetek_rtsx_openbsd_compat_spl_getGlobalLock(void);

spl_t Sinetek_rtsx_openbsd_compat_splbio(void);

spl_t Sinetek_rtsx_openbsd_compat_splhigh(void);

void Sinetek_rtsx_openbsd_compat_splx(spl_t val);

__END_DECLS

#endif // SINETEK_RTSX_COMPAT_OPENBSD_SPL_H
