// Copyright 2015 The Cobalt Authors. All Rights Reserved.
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

#include "cobalt/h5vcc/h5vcc.h"

#include "cobalt/h5vcc/h5vcc_metrics.h"
#include "cobalt/persistent_storage/persistent_settings.h"

namespace cobalt {
namespace h5vcc {

H5vcc::H5vcc(const Settings& settings) {
  accessibility_ = new H5vccAccessibility(settings.event_dispatcher);
  audio_config_array_ = new H5vccAudioConfigArray();
  c_val_ = new dom::CValView();
  crash_log_ = new H5vccCrashLog();
  metrics_ =
      new H5vccMetrics(settings.persistent_settings, settings.event_dispatcher);
  runtime_ = new H5vccRuntime(settings.event_dispatcher);
  settings_ =
      new H5vccSettings(settings.set_web_setting_func, settings.media_module,
                        settings.can_play_type_handler, settings.network_module,
#if SB_IS(EVERGREEN)
                        settings.updater_module,
#endif
                        settings.user_agent_data, settings.global_environment,
                        settings.persistent_settings);

  tizentube_ = new H5vccTizenTube();
  storage_ =
      new H5vccStorage(settings.network_module, settings.persistent_settings);
  trace_event_ = new H5vccTraceEvent();
  net_log_ = new H5vccNetLog(settings.network_module);
#if SB_IS(EVERGREEN)
  updater_ = new H5vccUpdater(settings.updater_module);
  system_ = new H5vccSystem(updater_);
#else
  system_ = new H5vccSystem();
#endif
}

void H5vcc::TraceMembers(script::Tracer* tracer) {
  tracer->Trace(accessibility_);
  tracer->Trace(audio_config_array_);
  tracer->Trace(c_val_);
  tracer->Trace(crash_log_);
  tracer->Trace(metrics_);
  tracer->Trace(runtime_);
  tracer->Trace(settings_);
  tracer->Trace(storage_);
  tracer->Trace(system_);
  tracer->Trace(trace_event_);
  tracer->Trace(net_log_);
#if SB_IS(EVERGREEN)
  tracer->Trace(updater_);
#endif
}

}  // namespace h5vcc
}  // namespace cobalt
