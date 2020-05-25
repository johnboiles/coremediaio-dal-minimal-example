//
//  ObjectStore.h
//  CMIOMinimalSample
//
//  Created by John Boiles  on 4/10/20.
//
//  CMIOMinimalSample is free software, and use is bound by the terms
//  set out in the LICENSE file distributed with this project.

#import <Foundation/Foundation.h>
#import <CoreMediaIO/CMIOHardwarePlugIn.h>

NS_ASSUME_NONNULL_BEGIN

@protocol CMIOObject

- (BOOL)hasPropertyWithAddress:(CMIOObjectPropertyAddress)address;
- (BOOL)isPropertySettableWithAddress:(CMIOObjectPropertyAddress)address;
- (UInt32)getPropertyDataSizeWithAddress:(CMIOObjectPropertyAddress)address qualifierDataSize:(UInt32)qualifierDataSize qualifierData:(const void*)qualifierData;
- (void)getPropertyDataWithAddress:(CMIOObjectPropertyAddress)address qualifierDataSize:(UInt32)qualifierDataSize qualifierData:(const void*)qualifierData dataSize:(UInt32)dataSize dataUsed:(UInt32 *)dataUsed data:(void *)data;
- (void)setPropertyDataWithAddress:(CMIOObjectPropertyAddress)address qualifierDataSize:(UInt32)qualifierDataSize qualifierData:(const void*)qualifierData dataSize:(UInt32)dataSize data:(const void*)data;

@end

@interface ObjectStore : NSObject

+ (ObjectStore *)SharedObjectStore;

+ (NSObject<CMIOObject> *)GetObjectWithId:(CMIOObjectID)objectId;

+ (NSString *)StringFromPropertySelector:(CMIOObjectPropertySelector)selector;

+ (BOOL)IsBridgedTypeForSelector:(CMIOObjectPropertySelector)selector;

- (NSObject<CMIOObject> *)getObject:(CMIOObjectID)objectID;

- (void)setObject:(id<CMIOObject>)object forObjectId:(CMIOObjectID)objectId;

@end

NS_ASSUME_NONNULL_END
