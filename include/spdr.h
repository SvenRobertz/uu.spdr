#ifndef UU_SPDR_H
#define UU_SPDR_H

/**
 * A tracing library
 */

#include "spdr-private.h"

/**
 * Context for the library
 */
struct spdr;

/**
 * Initializes the library
 */
int spdr_init(struct spdr **context);

/**
 * Shutdown the library
 */
void spdr_deinit(struct spdr* context);

/**
 * Provide your logging function if you want a trace stream to be produced.
 */
void spdr_set_log_fn(struct spdr *context,
		     void (*log_fn) (const char* line));

/**
 * Activates the recording of traces (off by default)
 */
void spdr_enable_trace(struct spdr *context, int traceon);

/**
 * Builds arguments of various types
 */
#define SPDR_INT(key, value)   UU_SPDR_INT(key, value)
#define SPDR_FLOAT(key, value) UU_SPDR_FLOAT(key, value)
#define SPDR_STR(key, value)   UU_SPDR_STR(key, value)

/**
 * An instant event
 */
#define SPDR_EVENT(spdr, cat, name)		\
	UU_SPDR_TRACE(spdr, cat, name, SPDR_EVENT)

/**
 * An instant event with one parameter
 */
#define SPDR_EVENT1(spdr, cat, name, arg0)				\
	UU_SPDR_TRACE1(spdr, cat, name, SPDR_EVENT, arg0)

/**
 * An instant event with two parameters
 */
#define SPDR_EVENT2(spdr, cat, name, arg0, arg1)	\
	UU_SPDR_TRACE2(spdr, cat, name, SPDR_EVENT, arg0, arg1)

/**
 * Begin a slice of work
 */
#define SPDR_BEGIN(spdr, cat, name)			\
	UU_SPDR_TRACE(spdr, cat, name, SPDR_BEGIN)

/**
 * Begin a slice of work, with one parameter.
 */
#define SPDR_BEGIN1(spdr, cat, name, arg0)				\
	UU_SPDR_TRACE1(spdr, cat, name, SPDR_BEGIN, arg0)

/**
 * Begin a slice of work, with two parameters
 */
#define SPDR_BEGIN2(spdr, cat, name, arg0, arg1)	\
	UU_SPDR_TRACE2(spdr, cat, name, SPDR_BEGIN, arg0, arg1)

/**
 * End a slice of work
 */
#define SPDR_END(spdr, cat, name)		\
	UU_SPDR_TRACE(spdr, cat, name, SPDR_END)

/**
 * Metadata.
 *
 * For instance to set the thread name:
 * @code
 * SPDR_METADATA1("thread_name", SPDR_STR("name", "My_Thread"))
 * @code
 */
#define SPDR_METADATA1(spdr, name, arg0)		\
	UU_SPDR_TRACE1(spdr, "__metadata", name, SPDR_METADATA, arg0)

/**
 * Mark the beginning and end of a scope
 *
 * Non standard. Only supported on select compilers.
 */
#define SPDR_SCOPE(spdr, cat, name)		\
	UU_SPDR_SCOPE_TRACE(spdr, cat, name)

#define SPDR_SCOPE1(spdr, cat, name, arg0)		\
	UU_SPDR_SCOPE_TRACE1(spdr, cat, name, arg0)

#define SPDR_SCOPE2(spdr, cat, name, arg0, arg1)	\
	UU_SPDR_SCOPE_TRACE2(spdr, cat, name, arg0, arg1)

#endif
