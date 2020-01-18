// Generated by gtkmmproc -- DO NOT MODIFY!


#include <glibmm.h>

#include <pangomm/glyphstring.h>
#include <pangomm/private/glyphstring_p.h>


// -*- c++ -*-
/* $Id: glyphstring.ccg,v 1.2 2006/05/30 17:14:21 murrayc Exp $ */

/*
 *
 * Copyright 1998-2002 The gtkmm Development Team
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

#include <glibmm/utility.h>
#include <pango/pangocairo.h>

namespace Pango
{

GlyphString::GlyphString(const Glib::ustring& text, const Analysis& analysis)
:
  gobject_(pango_glyph_string_new())
{
  pango_shape(text.c_str(), text.bytes(), const_cast<PangoAnalysis*>(analysis.gobj()), gobj());
}

Rectangle GlyphString::get_ink_extents(const Glib::RefPtr<const Font>& font) const
{
  Rectangle ink_rect;
  pango_glyph_string_extents(const_cast<PangoGlyphString*>(gobj()), const_cast<PangoFont*>(font->gobj()), ink_rect.gobj(), 0);
  return ink_rect;
}

Rectangle GlyphString::get_ink_extents(int start, int end, const Glib::RefPtr<const Font>& font) const
{
  Rectangle ink_rect;
  pango_glyph_string_extents_range(const_cast<PangoGlyphString*>(gobj()), start, end, const_cast<PangoFont*>(font->gobj()), ink_rect.gobj(), 0);
  return ink_rect;
}

Rectangle GlyphString::get_logical_extents(const Glib::RefPtr<const Font>& font) const
{
  Rectangle logical_rect;
  pango_glyph_string_extents(const_cast<PangoGlyphString*>(gobj()), const_cast<PangoFont*>(font->gobj()), 0, logical_rect.gobj());
  return logical_rect;
}

Rectangle GlyphString::get_logical_extents(int start, int end, const Glib::RefPtr<const Font>& font) const
{
  Rectangle logical_rect;
  pango_glyph_string_extents_range(const_cast<PangoGlyphString*>(gobj()), start, end, const_cast<PangoFont*>(font->gobj()), 0, logical_rect.gobj());
  return logical_rect;
}

Glib::ArrayHandle<int> GlyphString::get_logical_widths(const Glib::ustring& text, int embedding_level) const
{
  int* logical_widths = g_new(int, text.length());
  pango_glyph_string_get_logical_widths(const_cast<PangoGlyphString*>(gobj()), text.c_str(), text.bytes(), embedding_level, logical_widths);
  return Glib::ArrayHandle<int>(logical_widths, text.length(), Glib::OWNERSHIP_SHALLOW);
}

int GlyphString::index_to_x(const Glib::ustring& text, const Analysis& analysis, int index, bool trailing) const
{
  int x_pos;
  pango_glyph_string_index_to_x(const_cast<PangoGlyphString*>(gobj()), const_cast<gchar*>(text.c_str()), text.bytes(), const_cast<PangoAnalysis*>(analysis.gobj()), index, static_cast<int>(trailing), &x_pos);
  return x_pos;
}

void GlyphString::x_to_index(const Glib::ustring& text, const Analysis& analysis, int x_pos, int& index, bool& trailing) const
{
  gboolean trailing_temp = FALSE;
  pango_glyph_string_x_to_index(const_cast<PangoGlyphString*>(gobj()), const_cast<char*>(text.c_str()), text.bytes(), const_cast<PangoAnalysis*>(analysis.gobj()), x_pos, &index, &trailing_temp);
  trailing = trailing_temp;
}

Glib::ArrayHandle<GlyphInfo> GlyphString::get_glyphs() const
{
  return Glib::ArrayHandle<GlyphInfo>(reinterpret_cast<GlyphInfo*>(gobj()->glyphs), gobj()->num_glyphs, Glib::OWNERSHIP_NONE);
}

} //namespace Pango

namespace
{
} // anonymous namespace


namespace Glib
{

Pango::GlyphString wrap(PangoGlyphString* object, bool take_copy)
{
  return Pango::GlyphString(object, take_copy);
}

} // namespace Glib


namespace Pango
{


// static
GType GlyphString::get_type()
{
  return pango_glyph_string_get_type();
}

GlyphString::GlyphString()
:
  gobject_ (pango_glyph_string_new())
{}

GlyphString::GlyphString(const GlyphString& other)
:
  gobject_ ((other.gobject_) ? pango_glyph_string_copy(other.gobject_) : 0)
{}

GlyphString::GlyphString(PangoGlyphString* gobject, bool make_a_copy)
:
  // For BoxedType wrappers, make_a_copy is true by default.  The static
  // BoxedType wrappers must always take a copy, thus make_a_copy = true
  // ensures identical behaviour if the default argument is used.
  gobject_ ((make_a_copy && gobject) ? pango_glyph_string_copy(gobject) : gobject)
{}

GlyphString& GlyphString::operator=(const GlyphString& other)
{
  GlyphString temp (other);
  swap(temp);
  return *this;
}

GlyphString::~GlyphString()
{
  if(gobject_)
    pango_glyph_string_free(gobject_);
}

void GlyphString::swap(GlyphString& other)
{
  PangoGlyphString *const temp = gobject_;
  gobject_ = other.gobject_;
  other.gobject_ = temp;
}

PangoGlyphString* GlyphString::gobj_copy() const
{
  return pango_glyph_string_copy(gobject_);
}


void GlyphString::set_size(int new_len)
{
  pango_glyph_string_set_size(gobj(), new_len);
}

void GlyphString::get_extents(const Glib::RefPtr<const Font>& font, Rectangle& ink_rect, Rectangle& logical_rect) const
{
  pango_glyph_string_extents(const_cast<PangoGlyphString*>(gobj()), const_cast<PangoFont*>(Glib::unwrap<Font>(font)), (ink_rect).gobj(), (logical_rect).gobj());
}

void GlyphString::get_extents(int start, int end, const Glib::RefPtr<const Font>& font, Rectangle& ink_rect, Rectangle& logical_rect) const
{
  pango_glyph_string_extents_range(const_cast<PangoGlyphString*>(gobj()), start, end, const_cast<PangoFont*>(Glib::unwrap<Font>(font)), (ink_rect).gobj(), (logical_rect).gobj());
}

int GlyphString::get_width() const
{
  return pango_glyph_string_get_width(const_cast<PangoGlyphString*>(gobj()));
}


} // namespace Pango


