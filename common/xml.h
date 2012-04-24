/*
 * This file's contents are adapted from nxml.h in Naev
 * (github.com/bobbens/naev).
 */

#ifndef XML_H
#  define XML_H

#include <errno.h>

#include "libxml/parser.h"
#include "libxml/xmlwriter.h"

#define XML_NODE_START  1
#define XML_NODE_TEXT   3

/**
 * @brief Only handle nodes.
 */
#define xml_onlyNodes(n)    \
   if (((n)==NULL) || ((n)->type!=XML_NODE_START)) \
      continue;

/** checks to see if node n is of name s */
#define xml_isNode(n,s)    \
   ((n!=NULL) && ((n)->type==XML_NODE_START) && \
   (strcmp((char*)(n)->name,s)==0))

/** gets the next node */
#define xml_nextNode(n)     \
   ((n!=NULL) && ((n = n->next) != NULL))

/** gets the property s of node n. WARNING: MALLOCS! */
#define xml_nodeProp(n,s)     (char*)xmlGetProp(n,(xmlChar*)s)

/* get data different ways */
#define xml_raw(n)            ((char*)(n)->children->content)
#define xml_get(n)            (((n)->children == NULL) ? NULL : (char*)(n)->children->content)
#define xml_getInt(n)         ((xml_get(n) == NULL) ? 0  : strtol(  xml_raw(n), (char**)NULL, 10))
#define xml_getUInt(n)        ((xml_get(n) == NULL) ? 0  : strtoul( xml_raw(n), (char**)NULL, 10))
#define xml_getLong(n)        ((xml_get(n) == NULL) ? 0  : strtoll( xml_raw(n), (char**)NULL, 10))
#define xml_getULong(n)       ((xml_get(n) == NULL) ? 0  : strtoull(xml_raw(n), (char**)NULL, 10))
#define xml_getFloat(n)       ((xml_get(n) == NULL) ? 0. : atof(xml_raw(n)))
#define xml_getStrd(n)        ((xml_get(n) == NULL) ? NULL : strdup(xml_raw(n)))


/*
 * reader crap
 */
#define xmlr_int(n,s,i) \
   {if (xml_isNode(n,s)) { \
      i = xml_getInt(n); continue; }}
#define xmlr_uint(n,s,i) \
   {if (xml_isNode(n,s)) { \
      i = xml_getUInt(n); continue; }}
#define xmlr_long(n,s,l) \
   {if (xml_isNode(n,s)) { \
      l = xml_getLong(n); continue; }}
#define xmlr_ulong(n,s,l) \
   {if (xml_isNode(n,s)) { \
      l = xml_getULong(n); continue; }}
#define xmlr_float(n,s,f) \
   {if (xml_isNode(n,s)) { \
      f = xml_getFloat(n); continue; }}
#define xmlr_floatR(n,s,f) \
   {if (xml_isNode(n,s)) { \
      f = xml_getFloat(n); return 0; }}
#define xmlr_str(n,s,str) \
   {if (xml_isNode(n,s)) { \
      str = xml_get(n); continue; }}
#define xmlr_strd(n,s,str) \
   {if (xml_isNode(n,s)) { \
      if (str != NULL) { \
      str = ((xml_get(n) == NULL) ? NULL : strdup(xml_raw(n))); continue; }}}
#define xmlr_attr(n,s,a) \
   a = xml_nodeProp(n,s)

#endif /* XML_H */
