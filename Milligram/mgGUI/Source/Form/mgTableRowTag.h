/*
  Copyright (C) 1995-2012 by Michael J. Goodfellow

  This source code is distributed for free and may be modified, redistributed, and
  incorporated in other projects (commercial, non-commercial and open-source)
  without restriction.  No attribution to the author is required.  There is
  no requirement to make the source code available (no share-alike required.)

  This source code is distributed "AS IS", with no warranty expressed or implied.
  The user assumes all risks related to quality, accuracy and fitness of use.

  Except where noted, this source code is the sole work of the author, but it has 
  not been checked for any intellectual property infringements such as copyrights, 
  trademarks or patents.  The user assumes all legal risks.  The original version 
  may be found at "http://www.sea-of-memes.com".  The author is not responsible 
  for subsequent alterations.

  Retain this copyright notice and add your own copyrights and revisions above
  this notice.
*/
#ifndef MGTABLEROWTAG_H
#define MGTABLEROWTAG_H

#include "TextFormatter/mgTextBuffer.h"

class mgTableColTag;

class mgTableRowTag : public mgXMLTag
{
public:
  // constructor
  mgTableRowTag(
    const char* tagName)
  : mgXMLTag(tagName)
  {}

  // destructor
  virtual ~mgTableRowTag() 
  {}

  // tag starts
  virtual void tagOpen(
    mgXMLParser* parser);

  // attribute set
  virtual void tagAttr(
    mgXMLParser* parser,
    const char* attrName,
    const char* attrValue);

  // end of attributes
  virtual void tagEndAttrs(
    mgXMLParser* parser);

  // text content
  virtual void tagContent(
    mgXMLParser* parser,
    const char* text,
    int len);

  // add child tag.  parent tag now owns child pointer.
  virtual void tagChild(
    mgXMLParser* parser,
    mgXMLTag* tag);

  // tag ends
  virtual void tagClose(
    mgXMLParser* parser);

protected:
  int m_rowWeight;
  int m_topInset;
  int m_botInset;
  mgTableAlign m_halign;
  mgTableAlign m_valign;
  int m_units;

  friend class mgTableColTag;
};

#endif
