/* Copyright 2017 R. Thomas
 * Copyright 2017 Quarkslab
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef LIEF_ABSTRACT_HEADER_H_
#define LIEF_ABSTRACT_HEADER_H_

#include <iostream>
#include <set>

#include "LIEF/Visitable.hpp"
#include "LIEF/visibility.h"
#include "LIEF/types.hpp"

#include "LIEF/Abstract/enums.hpp"

namespace LIEF {
class DLL_PUBLIC Header : public Visitable {
  public:
  Header(void);
  Header(const Header&);
  Header& operator=(const Header&);
  virtual ~Header(void);


  ARCHITECTURES          architecture(void) const;
  const std::set<MODES>& modes(void)        const;
  OBJECT_TYPES           object_type(void)  const;
  uint64_t               entrypoint(void)   const;

  //! @brief Method so that the ``visitor`` can visit us
  virtual void           accept(Visitor& visitor) const override;

  void architecture(ARCHITECTURES arch);
  void modes(const std::set<MODES>& m);
  void object_type(OBJECT_TYPES type);
  void entrypoint(uint64_t entrypoint);

  DLL_PUBLIC friend std::ostream& operator<<(std::ostream& os, const Header& hdr);

  protected:
  ARCHITECTURES   architecture_;
  std::set<MODES> modes_;
  OBJECT_TYPES    object_type_;
  uint64_t        entrypoint_;


};
}

#endif
