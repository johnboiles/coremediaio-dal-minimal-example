//
//  PlugIn.h
//  CMIOMinimalSample
//
//  Created by John Boiles  on 4/9/20.
//
//  CMIOMinimalSample is free software, and use is bound by the terms
//  set out in the LICENSE file distributed with this project.

#import <Foundation/Foundation.h>
#import <CoreMediaIO/CMIOHardwarePlugIn.h>

#import "ObjectStore.h"

NS_ASSUME_NONNULL_BEGIN

@interface PlugIn : NSObject <CMIOObject>

@property CMIOObjectID objectId;

+ (PlugIn *)SharedPlugIn;

- (void)initialize;

- (void)teardown;

@end

NS_ASSUME_NONNULL_END
