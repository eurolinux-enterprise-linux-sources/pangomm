// Generated by gmmproc 2.49.5 -- DO NOT MODIFY!


#include <glibmm.h>

#include <pangomm/item.h>
#include <pangomm/private/item_p.h>


/* Copyright (C) 2002 The gtkmm Development Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free
 * Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include <pangomm/font.h>
#include <pangomm/attributes.h>
#include <pangomm/glyphstring.h>

namespace Pango
{

Analysis::Analysis()
{}

Analysis::Analysis(const PangoAnalysis* src)
:
  gobject_ (*src)
{}

SListHandle_Attribute Analysis::get_extra_attrs() const
{
  return SListHandle_Attribute(gobj()->extra_attrs, Glib::OWNERSHIP_NONE);
}


Item::Item(const Item& src)
:
  gobject_ ((src.gobject_) ? pango_item_copy(src.gobject_) : 0)
{}

Item::Item(PangoItem* castitem, bool make_a_copy)
{
  // For BoxedType wrappers, make_a_copy is true by default.  The static
  // BoxedType wrappers must always take a copy, thus make_a_copy = true
  // ensures identical behaviour if the default argument is used.

  if(make_a_copy)
  {
    if(castitem)
      gobject_ = pango_item_copy(castitem);
    else
      gobject_ = 0;
  }
  else
  {
    // It was given to us by a function which has already made a copy for us to keep.
    gobject_ = castitem;
  }
}

Item& Item::operator=(const Item& src)
{
  PangoItem *const new_gobject = (src.gobject_) ? pango_item_copy(src.gobject_) : 0;

  if(gobject_)
    pango_item_free(gobject_);
  gobject_ = new_gobject;

  return *this;
}

Item::~Item()
{
  if(gobject_)
    pango_item_free(gobject_);
}

PangoItem* Item::gobj_copy() const
{
  return pango_item_copy(gobject_);
}

Analysis Item::get_analysis() const
{
  return Analysis(&gobj()->analysis);
}

Glib::ustring Item::get_segment(const Glib::ustring& text) const
{
  const char *const start = text.data() + gobj()->offset;
  return Glib::ustring(start, start + gobj()->length);
}

Pango::GlyphString Item::shape(const Glib::ustring& text) const
{
  return GlyphString(text, get_analysis());
}

} /* namespace Pango */


namespace Glib
{

Pango::Analysis& wrap(PangoAnalysis* object)
{
  return *reinterpret_cast<Pango::Analysis*>(object);
}

const Pango::Analysis& wrap(const PangoAnalysis* object)
{
  return *reinterpret_cast<const Pango::Analysis*>(object);
}

Pango::Item wrap(PangoItem* object, bool take_copy)
{
  return Pango::Item(object, take_copy);
}

} /* namespace Glib */


namespace
{
} // anonymous namespace


namespace Pango
{


Glib::RefPtr<Font> Analysis::get_font()
{
  Glib::RefPtr<Font> ref_ptr(Glib::wrap(gobj()->font));

  if(ref_ptr)
    ref_ptr->reference();

  return ref_ptr;
}

Glib::RefPtr<const Font> Analysis::get_font() const
{
  Glib::RefPtr<const Font> ref_ptr(Glib::wrap(gobj()->font));

  if(ref_ptr)
    ref_ptr->reference();

  return ref_ptr;
}

guint8 Analysis::get_level() const
{
  return gobj()->level;
}

Language Analysis::get_language() const
{
  return Language(gobj()->language);
}


} // namespace Pango


namespace Pango
{


Item Item::split(int split_index, int split_offset)
{
  return Item((pango_item_split(gobj(), split_index, split_offset)));
}

int Item::get_offset() const
{
  return gobj()->offset;
}

int Item::get_length() const
{
  return gobj()->length;
}

int Item::get_num_chars() const
{
  return gobj()->num_chars;
}


} // namespace Pango


