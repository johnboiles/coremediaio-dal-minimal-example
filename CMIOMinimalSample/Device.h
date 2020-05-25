//
//  Device.h
//  CMIOMinimalSample
//
//  Created by John Boiles  on 4/10/20.
//
//  CMIOMinimalSample is free software, and use is bound by the terms
//  set out in the LICENSE file distributed with this project.

#import <Foundation/Foundation.h>

#import "ObjectStore.h"

NS_ASSUME_NONNULL_BEGIN

@interface Device : NSObject <CMIOObject>

@property CMIOObjectID objectId;
@property CMIOObjectID pluginId;
@property CMIOObjectID streamId;

@end

NS_ASSUME_NONNULL_END
