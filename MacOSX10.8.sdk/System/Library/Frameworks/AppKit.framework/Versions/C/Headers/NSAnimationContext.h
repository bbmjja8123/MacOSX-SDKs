/*
    NSAnimationContext.h
    Application Kit
    Copyright (c) 2006-2012, Apple Inc.
    All rights reserved.
*/

#import <AppKit/AppKitDefines.h>
#import <Foundation/NSObject.h>
#import <Foundation/NSDate.h>

@class CAMediaTimingFunction;

NS_CLASS_AVAILABLE(10_5, NA)
@interface NSAnimationContext : NSObject {
@private
    NSTimeInterval _duration;
    id _reserved[4];
    unsigned int _allowsImplicitAnimation:1;
    unsigned int _isImplicitContext:1;
    unsigned int __reserved:30;

}
+ (void)runAnimationGroup:(void (^)(NSAnimationContext *context))changes completionHandler:(void (^)(void))completionHandler NS_AVAILABLE_MAC(10_7);

+ (void)beginGrouping;
+ (void)endGrouping;

+ (NSAnimationContext *)currentContext;

@property NSTimeInterval duration;
@property(retain) CAMediaTimingFunction *timingFunction NS_AVAILABLE_MAC(10_7);

#if NS_BLOCKS_AVAILABLE
@property(copy) void (^completionHandler)(void) NS_AVAILABLE_MAC(10_7);
#endif

/* Determine if animations are enabled or not. Using the -animator proxy will automatically set allowsImplicitAnimation to YES. When YES, other properties can implicitly animate along with the initially changed property. For instance, calling [[view animator] setFrame:frame] will allow subviews to also animate their frame positions. This is only applicable when layer backed on Mac OS 10.8 and later. The default value is NO.
 */
@property BOOL allowsImplicitAnimation NS_AVAILABLE_MAC(10_8);

@end
