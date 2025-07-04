// Copyright 2023 The Cobalt Authors. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef COBALT_CSS_PARSER_SWITCHES_H_
#define COBALT_CSS_PARSER_SWITCHES_H_

#include <map>
#include <string>

namespace cobalt {
namespace css_parser {
namespace switches {

#if !defined(COBALT_BUILD_TYPE_GOLD)
extern const char kOnCssError[];
extern const char kOnCssErrorHelp[];
extern const char kOnCssWarning[];
extern const char kOnCssWarningHelp[];
#endif  // !defined(COBALT_BUILD_TYPE_GOLD)

std::map<std::string, const char*> HelpMap();

}  // namespace switches
}  // namespace css_parser
}  // namespace cobalt

#endif  // COBALT_CSS_PARSER_SWITCHES_H_
