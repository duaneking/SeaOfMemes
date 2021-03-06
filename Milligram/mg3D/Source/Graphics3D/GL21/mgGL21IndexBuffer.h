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
#if !defined(MGGL21INDEXES_H) && defined(SUPPORT_GL21)
#define MGGL21INDEXES_H

#include "Graphics3D/mgIndexBuffer.h"

class mgGL21IndexBuffer : public mgIndexBuffer
{
public:
  // constructor
  mgGL21IndexBuffer(
    int size,
    BOOL dynamic = false,
    BOOL longIndexes = false);

  // destructor
  virtual ~mgGL21IndexBuffer();

  // reset buffer for reuse
  virtual void reset();

  // move buffer to display.  memory deleted.
  virtual void loadDisplay();

  // delete buffer from display
  virtual void unloadDisplay();

protected:
  mgBufferHandle m_buffer;
  BOOL m_updateBuffer;

  friend class mgGL21Services;
};

#endif
