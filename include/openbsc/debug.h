#ifndef _DEBUG_H
#define _DEBUG_H

#define DRLL		0x0001
#define DCC		0x0002
#define DMM		0x0004
#define DRR		0x0008

#ifdef DEBUG
#define DEBUGP(ss, args, ...)	debugp(ss, args, ...)
#else
#define DEBUGP(xss, args, ...) 
#endif

#endif /* _DEBUG_H */
