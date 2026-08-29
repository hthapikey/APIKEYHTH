#pragma once

#include <functional>
#include <string>

#if defined(__GNUC__)
#define HTH_API __attribute__((visibility("default")))
#else
#define HTH_API
#endif

namespace HTHApiKey {

using Callback = std::function<void()>;

HTH_API void configure(const std::string &packageToken,
                       const std::string &version = "1.0.0");
HTH_API void paid(Callback onSuccess);
HTH_API void reset();

HTH_API std::string getKey();
HTH_API std::string getExpiryDate();
HTH_API std::string getUDID();
HTH_API std::string getDeviceModel();
HTH_API std::string getLoginIP();
HTH_API std::string getPackageName();
HTH_API bool isLicenseValid();
} // namespace HTHApiKey

extern "C" HTH_API int hth_apikey_quick_validate(void);

#if defined(__OBJC__)
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface apikeyios : NSObject
+ (void)configureWithPackageToken:(NSString *)packageToken;
+ (void)setPackageVersion:(NSString *)version;
+ (void)paid:(void (^)(void))execute;
+ (void)reset;
+ (NSString *)getKey;
+ (NSString *)getExpiryDate;
+ (NSString *)getUDID;
+ (NSString *)getDeviceModel;
+ (NSString *)getLoginIP;
+ (NSString *)getPackageName;
+ (BOOL)isLicenseValid;
@end

FOUNDATION_EXPORT int apikey_quick_validate(void);
FOUNDATION_EXPORT BOOL HTHBridgeHandleIncomingURL(NSURL *url);

NS_ASSUME_NONNULL_END
#endif
