// Copyright 2016 The Cobalt Authors. All Rights Reserved.
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

#ifndef COBALT_NETWORK_SWITCHES_H_
#define COBALT_NETWORK_SWITCHES_H_

#include <map>
#include <string>

namespace cobalt {
namespace network {
namespace switches {

#if defined(ENABLE_DEBUG_COMMAND_LINE_SWITCHES)
extern const char kNetLog[];
extern const char kNetLogCaptureMode[];
extern const char kUserAgent[];
extern const char kMaxNetworkDelay[];
extern const char kMaxNetworkDelayHelp[];
extern const char kDisableInAppDial[];
extern const char kQuicConnectionOptions[];
extern const char kQuicConnectionOptionsHelp[];
extern const char kQuicClientConnectionOptions[];
extern const char kQuicClientConnectionOptionsHelp[];
#endif  // ENABLE_DEBUG_COMMAND_LINE_SWITCHES
extern const char kDisableQuic[];
extern const char kDisableHttp2[];

std::map<std::string, const char*> HelpMap();

}  // namespace switches
}  // namespace network
}  // namespace cobalt

#endif  // COBALT_NETWORK_SWITCHES_H_
