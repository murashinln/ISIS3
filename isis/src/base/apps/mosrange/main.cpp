/** This is free and unencumbered software released into the public domain.

The authors of ISIS do not claim copyright on the contents of this file.
For more details about the LICENSE terms and the AUTHORS, you will
find files of those names at the top level of this repository. **/

/* SPDX-License-Identifier: CC0-1.0 */
#include "Isis.h"

#include "Application.h"
#include "Pvl.h"
#include "UserInterface.h"
#include "mosrange.h"

using namespace Isis;

void IsisMain() {
  UserInterface &ui = Application::GetUserInterface();
  Pvl results = mosrange(ui);

  for (int resultIndex = 0; resultIndex < results.groups(); resultIndex++) {
      Application::Log(results.group(resultIndex));
  }
}
