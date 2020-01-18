// -*- c++ -*-
// Generated by gtkmmproc -- DO NOT MODIFY!
#ifndef _PANGOMM_COVERAGE_H
#define _PANGOMM_COVERAGE_H


#include <glibmm/ustring.h>
#include <sigc++/sigc++.h>

/* $Id: coverage.hg,v 1.1 2003/01/21 13:41:03 murrayc Exp $ */

/* coverage.h
 *
 * Copyright (C) 1998-1999 The gtkmm Development Team
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

#include <glibmm/arrayhandle.h>
#include <pango/pango-font.h>


namespace Pango
{


/** @addtogroup pangommEnums pangomm Enums and Flags */

/** 
 * 
 * @ingroup pangommEnums
 */
enum CoverageLevel
{
  COVERAGE_NONE,
  COVERAGE_FALLBACK,
  COVERAGE_APPROXIMATE,
  COVERAGE_EXACT
};

} // namespace Pango


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class Value<Pango::CoverageLevel> : public Glib::Value_Enum<Pango::CoverageLevel>
{
public:
  static GType value_type() G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Pango
{


/** A Pango::Coverage represents a map from ISO-10646 character point to Pango::CoverageLevel.
 * It is often necessary in pango to determine if a particular font can represent a particular character,
 * and also how well it can represent that character. Pango::Coverage holds this information.
 */
class Coverage
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef Coverage CppObjectType;
  typedef PangoCoverage BaseObjectType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  static Glib::RefPtr<Coverage> create();

  /** Increment the reference count for this object.
   * You should never need to do this manually - use the object via a RefPtr instead.
   */
  void reference()   const;

  /** Decrement the reference count for this object.
   * You should never need to do this manually - use the object via a RefPtr instead.
   */
  void unreference() const;

  ///Provides access to the underlying C instance.
  PangoCoverage*       gobj();

  ///Provides access to the underlying C instance.
  const PangoCoverage* gobj() const;

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  PangoCoverage* gobj_copy() const;

protected:
  // Do not derive this.  Pango::Coverage can neither be constructed nor deleted.
  Coverage();
  void operator delete(void*, std::size_t);

private:
  // noncopyable
  Coverage(const Coverage&);
  Coverage& operator=(const Coverage&);


   //pango ref doc: "This function may now be unecessary since we refcount the structure. Mail otaylor redhat.com if you use it."
  

public:
  
  /** Convert data generated from pango_converage_to_bytes() back
   * to a Pango::Coverage
   * @param bytes Binary data representing a Pango::Coverage.
   * @param n_bytes The size of @a bytes in bytes.
   * @return A newly allocated Pango::Coverage, or <tt>0</tt> if
   * the data was invalid.
   */
  static Glib::RefPtr<Coverage> create(const guchar* bytes, int n_bytes);

  //_WRAP_METHOD(Glib::RefPtr<Coverage> copy() const, pango_coverage_copy) //see above

  
  /** Determine whether a particular index is covered by @a coverage
   * @param index The index to check.
   * @return The coverage level of @a coverage for character @a index.
   */
  CoverageLevel get(int index) const;
  
  /** Modify a particular index within @a coverage
   * @param index The index to modify.
   * @param level The new level for @a index.
   */
  void set(int index, CoverageLevel level);
  
  /** Set the coverage for each index in @a coverage to be the max (better)
   * value of the current coverage for the index and the coverage for
   * the corresponding index in @a other.
   * @param other Another Pango::Coverage.
   */
  void max(const Glib::RefPtr<Coverage>& other) const;

  /** Convert the coverage map into a flat binary format.
   * @return An array of bytes representing the coverage map.
   */
  Glib::ArrayHandle<unsigned char> to_bytes() const;


};

} // namespace Pango


namespace Glib
{

  /** A Glib::wrap() method for this object.
   * 
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Pango::Coverage
   */
  Glib::RefPtr<Pango::Coverage> wrap(PangoCoverage* object, bool take_copy = false);

} // namespace Glib


#endif /* _PANGOMM_COVERAGE_H */

