//
//  PlugInMain.mm
//  CMIOMinimalSample
//
//  Created by John Boiles  on 4/9/20.
//
//  CMIOMinimalSample is free software, and use is bound by the terms
//  set out in the LICENSE file distributed with this project.

#import <CoreMediaIO/CMIOHardwarePlugin.h>

#import "PlugInInterface.h"
#import "Logging.h"

//! PlugInMain is the entrypoint for the plugin
extern "C" {
    void* PlugInMain(CFAllocatorRef allocator, CFUUIDRef requestedTypeUUID) {
        DLogFunc(@"");
        if (!CFEqual(requestedTypeUUID, kCMIOHardwarePlugInTypeID)) {
            return 0;
        }

        return PlugInRef();
    }
}
