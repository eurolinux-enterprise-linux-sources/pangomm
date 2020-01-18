// -*- c++ -*-
// Generated by gtkmmproc -- DO NOT MODIFY!
#ifndef _PANGOMM_RENDERER_H
#define _PANGOMM_RENDERER_H


#include <glibmm/ustring.h>
#include <sigc++/sigc++.h>

/* $Id: renderer.hg,v 1.4 2006/06/10 15:26:24 murrayc Exp $ */

/* renderer.h
 *
 * Copyright(C) 2004 The gtkmm Development Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or(at your option) any later version.
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


#include <glibmm/object.h>
#include <pangomm/context.h>
#include <pangomm/layoutrun.h> //Has a typedef for GlyphItem
#include <pangomm/glyphstring.h>
#include <pangomm/layout.h>
#include <pangomm/layoutline.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _PangoRenderer PangoRenderer;
typedef struct _PangoRendererClass PangoRendererClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Pango
{ class Renderer_Class; } // namespace Pango
namespace Pango
{


/** @addtogroup pangommEnums pangomm Enums and Flags */

/** 
 * 
 * @ingroup pangommEnums
 */
enum RenderPart
{
  RENDER_PART_FOREGROUND,
  RENDER_PART_BACKGROUND,
  RENDER_PART_UNDERLINE,
  RENDER_PART_STRIKETHROUGH
};

} // namespace Pango


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class Value<Pango::RenderPart> : public Glib::Value_Enum<Pango::RenderPart>
{
public:
  static GType value_type() G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Pango
{


/** Pango::Renderer is a base class that contains the necessary logic for rendering a Pango::Layout or Pango::LayoutLine. 
 * By subclassing Pango::Renderer and overriding operations such as draw_glyphs and draw_rectangle, 
 * renderers for particular font backends and destinations can be created.
 */

class Renderer : public Glib::Object
{
  
#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  typedef Renderer CppObjectType;
  typedef Renderer_Class CppClassType;
  typedef PangoRenderer BaseObjectType;
  typedef PangoRendererClass BaseClassType;

private:  friend class Renderer_Class;
  static CppClassType renderer_class_;

private:
  // noncopyable
  Renderer(const Renderer&);
  Renderer& operator=(const Renderer&);

protected:
  explicit Renderer(const Glib::ConstructParams& construct_params);
  explicit Renderer(PangoRenderer* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:
  virtual ~Renderer();

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static GType get_type()      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  PangoRenderer*       gobj()       { return reinterpret_cast<PangoRenderer*>(gobject_); }

  ///Provides access to the underlying C GObject.
  const PangoRenderer* gobj() const { return reinterpret_cast<PangoRenderer*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  PangoRenderer* gobj_copy();

private:

 
protected:
 
public:

  
  /** Draws @a layout with the specified Pango::Renderer.
   * 
   * @newin{1,8}
   * @param layout A Pango::Layout.
   * @param x X position of left edge of baseline, in user space coordinates
   * in Pango units.
   * @param y Y position of left edge of baseline, in user space coordinates
   * in Pango units.
   */
  void draw_layout(const Glib::RefPtr<Layout>& layout, int x, int y);
  
  /** Draws @a line with the specified Pango::Renderer.
   * 
   * @newin{1,8}
   * @param line A Pango::LayoutLine.
   * @param x X position of left edge of baseline, in user space coordinates
   * in Pango units.
   * @param y Y position of left edge of baseline, in user space coordinates
   * in Pango units.
   */
  void draw_layout_line(const Glib::RefPtr<LayoutLine>& line, int x, int y);
  
  /** Draws the glyphs in @a glyphs with the specified Pango::Renderer.
   * 
   * @newin{1,8}
   * @param font A Pango::Font.
   * @param glyphs A Pango::GlyphString.
   * @param x X position of left edge of baseline, in user space coordinates
   * in Pango units.
   * @param y Y position of left edge of baseline, in user space coordinates
   * in Pango units.
   */
  void draw_glyphs(const Glib::RefPtr<Font>& font, const GlyphString& glyphs, int x, int y);
  
  /** Draws the glyphs in @a glyph_item with the specified Pango::Renderer,
   * embedding the text associated with the glyphs in the output if the
   * output format supports it (PDF for example).
   * 
   * Note that @a text is the start of the text for layout, which is then
   * indexed by <tt> @a glyph_item->item->offset</tt>.
   * 
   * If @a text is <tt>0</tt>, this simply calls draw_glyphs().
   * 
   * The default implementation of this method simply falls back to
   * draw_glyphs().
   * 
   * @newin{1,22}
   * @param text The UTF-8 text that @a glyph_item refers to, or <tt>0</tt>.
   * @param glyph_item A Pango::GlyphItem.
   * @param x X position of left edge of baseline, in user space coordinates
   * in Pango units.
   * @param y Y position of left edge of baseline, in user space coordinates
   * in Pango units.
   */
  void draw_glyph_item(const Glib::ustring& text, const GlyphItem& glyph_item, int x, int y);
  
  /** Draws an axis-aligned rectangle in user space coordinates with the
   * specified Pango::Renderer.
   * 
   * This should be called while @a renderer is already active.  Use
   * activate() to activate a renderer.
   * 
   * @newin{1,8}
   * @param part Type of object this rectangle is part of.
   * @param x X position at which to draw rectangle, in user space coordinates in Pango units.
   * @param y Y position at which to draw rectangle, in user space coordinates in Pango units.
   * @param width Width of rectangle in Pango units in user space coordinates.
   * @param height Height of rectangle in Pango units in user space coordinates.
   */
  void draw_rectangle(RenderPart part, int x, int y, int width, int height);
  
  /** Draw a squiggly line that approximately covers the given rectangle
   * in the style of an underline used to indicate a spelling error.
   * (The width of the underline is rounded to an integer number
   * of up/down segments and the resulting rectangle is centered
   * in the original rectangle)
   * 
   * This should be called while @a renderer is already active.  Use
   * activate() to activate a renderer.
   * 
   * @newin{1,8}
   * @param x X coordinate of underline, in Pango units in user coordinate system.
   * @param y Y coordinate of underline, in Pango units in user coordinate system.
   * @param width Width of underline, in Pango units in user coordinate system.
   * @param height Height of underline, in Pango units in user coordinate system.
   */
  void draw_error_underline(int x, int y, int width, int height);
  
  /** Draws a trapezoid with the parallel sides aligned with the X axis
   * using the given Pango::Renderer; coordinates are in device space.
   * 
   * @newin{1,8}
   * @param part Type of object this trapezoid is part of.
   * @param y1 Y coordinate of top of trapezoid.
   * @param x11 X coordinate of left end of top of trapezoid.
   * @param x21 X coordinate of right end of top of trapezoid.
   * @param y2 Y coordinate of bottom of trapezoid.
   * @param x12 X coordinate of left end of bottom of trapezoid.
   * @param x22 X coordinate of right end of bottom of trapezoid.
   */
  void draw_trapezoid(RenderPart part, double y1, double x11, double x21, double y2, double x12, double x22);
  
  /** Draws a single glyph with coordinates in device space.
   * 
   * @newin{1,8}
   * @param font A Pango::Font.
   * @param glyph The glyph index of a single glyph.
   * @param x X coordinate of left edge of baseline of glyph.
   * @param y Y coordinate of left edge of baseline of glyph.
   */
  void draw_glyph(const Glib::RefPtr<Font>& font, Glyph glyph, double x, double y);

  
  /** Does initial setup before rendering operations on @a renderer.
   * deactivate() should be called when done drawing.
   * Calls such as draw_layout() automatically
   * activate the layout before drawing on it. Calls to
   * activate() and deactivate() can
   * be nested and the renderer will only be initialized and
   * deinitialized once.
   * 
   * @newin{1,8}
   */
  void activate();
  
  /** Cleans up after rendering operations on @a renderer. See
   * docs for activate().
   * 
   * @newin{1,8}
   */
  void deactivate();

  
  /** Informs Pango that the way that the rendering is done
   * for @a part has changed in a way that would prevent multiple
   * pieces being joined together into one drawing call. For
   * instance, if a subclass of Pango::Renderer was to add a stipple
   * option for drawing underlines, it needs to call
   * 
   * [C example ellipted]
   * 
   * When the stipple changes or underlines with different stipples
   * might be joined together. Pango automatically calls this for
   * changes to colors. (See set_color())
   * 
   * @newin{1,8}
   * @param part The part for which rendering has changed.
   */
  void part_changed(RenderPart part);

  
  /** Sets the color for part of the rendering.
   * 
   * @newin{1,8}
   * @param part The part to change the color of.
   * @param color The new color or <tt>0</tt> to unset the current color.
   */
  void set_color(RenderPart part, const Color& color);
  
 
  /** Gets the current rendering color for the specified part.
   * 
   * @newin{1,8}
   * @param part The part to get the color for.
   * @return The color for the specified part, or <tt>0</tt>
   * if it hasn't been set and should be inherited from the
   * environment.
   */
  Color get_color(RenderPart part) const;

  
  /** Sets the transformation matrix that will be applied when rendering.
   * 
   * @newin{1,8}
   * @param matrix A Pango::Matrix, or <tt>0</tt> to unset any existing matrix.
   * (No matrix set is the same as setting the identity matrix.).
   */
  void set_matrix(const Matrix& matrix);

  //TODO: Documentation:
  Matrix get_matrix() const;
  

  /** Gets the layout currently being rendered using @a renderer.
   * Calling this function only makes sense from inside a subclass's
   * methods, like in its draw_shape<!---->() for example.
   * 
   * The returned layout should not be modified while still being
   * rendered.
   * 
   * @newin{1,20}
   * @return The layout, or <tt>0</tt> if no layout is being
   * rendered using @a renderer at this time.
   */
  Glib::RefPtr<Layout> get_layout();
  
  /** Gets the layout currently being rendered using @a renderer.
   * Calling this function only makes sense from inside a subclass's
   * methods, like in its draw_shape<!---->() for example.
   * 
   * The returned layout should not be modified while still being
   * rendered.
   * 
   * @newin{1,20}
   * @return The layout, or <tt>0</tt> if no layout is being
   * rendered using @a renderer at this time.
   */
  Glib::RefPtr<const Layout> get_layout() const;

  
  /** Gets the layout line currently being rendered using @a renderer.
   * Calling this function only makes sense from inside a subclass's
   * methods, like in its draw_shape<!---->() for example.
   * 
   * The returned layout line should not be modified while still being
   * rendered.
   * 
   * @newin{1,20}
   * @return The layout line, or <tt>0</tt> if no layout line is being
   * rendered using @a renderer at this time.
   */
  Glib::RefPtr<LayoutLine> get_layout_line();
  
  /** Gets the layout line currently being rendered using @a renderer.
   * Calling this function only makes sense from inside a subclass's
   * methods, like in its draw_shape<!---->() for example.
   * 
   * The returned layout line should not be modified while still being
   * rendered.
   * 
   * @newin{1,20}
   * @return The layout line, or <tt>0</tt> if no layout line is being
   * rendered using @a renderer at this time.
   */
  Glib::RefPtr<const LayoutLine> get_layout_line() const;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

} /* namespace Pango */


namespace Glib
{
  /** A Glib::wrap() method for this object.
   * 
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Pango::Renderer
   */
  Glib::RefPtr<Pango::Renderer> wrap(PangoRenderer* object, bool take_copy = false);
}


#endif /* _PANGOMM_RENDERER_H */

