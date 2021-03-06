// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CC_SCHEDULER_COMMIT_EARLYOUT_REASON_H_
#define CC_SCHEDULER_COMMIT_EARLYOUT_REASON_H_

#include "base/logging.h"
#include "cc/base/cc_export.h"

namespace cc {

namespace proto {
class CommitEarlyOutReason;
}

enum class CommitEarlyOutReason {
  ABORTED_OUTPUT_SURFACE_LOST,
  ABORTED_NOT_VISIBLE,
  ABORTED_DEFERRED_COMMIT,
  ABORTED_FRAME_SKIPPED,
  FINISHED_NO_UPDATES,
};

// Please update the To/From Protobuf methods for any updates made to
// CommitEarlyOutReason enum.
CC_EXPORT CommitEarlyOutReason
CommitEarlyOutReasonFromProtobuf(const proto::CommitEarlyOutReason& proto);
CC_EXPORT void CommitEarlyOutReasonToProtobuf(
    CommitEarlyOutReason reason,
    proto::CommitEarlyOutReason* proto);

inline const char* CommitEarlyOutReasonToString(CommitEarlyOutReason reason) {
  switch (reason) {
    case CommitEarlyOutReason::ABORTED_OUTPUT_SURFACE_LOST:
      return "CommitEarlyOutReason::ABORTED_OUTPUT_SURFACE_LOST";
    case CommitEarlyOutReason::ABORTED_NOT_VISIBLE:
      return "CommitEarlyOutReason::ABORTED_NOT_VISIBLE";
    case CommitEarlyOutReason::ABORTED_DEFERRED_COMMIT:
      return "CommitEarlyOutReason::ABORTED_DEFERRED_COMMIT";
    case CommitEarlyOutReason::ABORTED_FRAME_SKIPPED:
      return "CommitEarlyOutReason::ABORTED_FRAME_SKIPPED";
    case CommitEarlyOutReason::FINISHED_NO_UPDATES:
      return "CommitEarlyOutReason::FINISHED_NO_UPDATES";
  }
  NOTREACHED();
  return "???";
}

inline bool CommitEarlyOutHandledCommit(CommitEarlyOutReason reason) {
  return reason == CommitEarlyOutReason::FINISHED_NO_UPDATES;
}

}  // namespace cc

#endif  // CC_SCHEDULER_COMMIT_EARLYOUT_REASON_H_
