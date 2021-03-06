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

#include "stdafx.h"

#ifdef DEBUG_MEMORY
const char THIS_FILE[] = __FILE__;
#define new new(THIS_FILE, __LINE__)
#endif

#include "GUI/mgToolkit.h"

#include "GenericStyle/mgButtonFace.h"
#include "GenericStyle/mgGenericStyle.h"

//--------------------------------------------------------------
// constructor
mgButtonFace::mgButtonFace(
  mgGenericStyle* style,
  const char* key)
{
  m_font = style->getFont(key);
  m_frame = style->getFrame(key);
  style->getColor(key, m_textColor);
}

//--------------------------------------------------------------
// destructor
mgButtonFace::~mgButtonFace()
{
}

//--------------------------------------------------------------
// get minimum size of control
void mgButtonFace::minimumSize(
  mgContext* gc,
  const mgGenericArgs& args,
  mgDimension& size) const 
{
  preferredSize(gc, args, size);
}

//--------------------------------------------------------------
// get preferred size of control
void mgButtonFace::preferredSize(
  mgContext* gc,
  const mgGenericArgs& args,
  mgDimension& size) const 
{
  mgString label;
  args.lookup("label", label);

  gc->setFont(m_font);
  mgRectangle bounds;
  mgPoint endPt;
  gc->stringExtent(label, label.length(), endPt, bounds);

  mgDimension labelSize(bounds.m_width, bounds.m_height);
  if (m_frame != NULL)
    m_frame->getOutsideSize(labelSize, size);
  else size = labelSize;
}

//--------------------------------------------------------------
// draw in a rectangular area
void mgButtonFace::paint(
  mgContext* gc,
  const mgGenericArgs& args,
  const mgDimension& size) const 
{
  mgRectangle inside(0, 0, size.m_width, size.m_height);
  if (m_frame != NULL)
  {
    m_frame->paintBackground(gc, 0, 0, size.m_width, size.m_height);
    m_frame->getInsideRect(inside);
  }

  mgString label;
  args.lookup("label", label);

  mgRectangle bounds;
  mgPoint endPt;
  gc->stringExtent(label, label.length(), endPt, bounds);

  gc->setDrawMode(MG_DRAW_RGB);
  gc->setFont(m_font);
  gc->setTextColor(m_textColor);
  gc->drawString(label, label.length(), inside.m_x + (inside.m_width - bounds.m_width)/2, 
                inside.m_y + (inside.m_height - bounds.m_height)/2 + m_font->getAscent());

  if (m_frame != NULL)
  {
    gc->setDrawMode(MG_DRAW_ALL);
    m_frame->paintForeground(gc, 0, 0, size.m_width, size.m_height);
  }
}
