#import <Cocoa/Cocoa.h>
#import <CoreGraphics/CoreGraphics.h>
#import <CoreGraphics/CGColor.h>

#import "qui.h"
#import "platform.h"
#import "private.h"

#import "font-private.h"

QuFont *QuFont_Arial;
QuFont *QuFont_Button;
QuFont *QuFont_Times;

QuFont *_QuFontA_ct_font(CTFontRef ct_font)
{
    QuFont *font = calloc(1, sizeof(QuFont));

    font->_font = ct_font;
    font->_keys[0] = kCTFontAttributeName;
    font->_values[0] = ct_font;

    font->_attrs = CFDictionaryCreate(
        kCFAllocatorDefault,
        (const void**)font->_keys,
        (const void**)font->_values,
        sizeof(font->_keys) / sizeof(font->_keys[0]),
        &kCFTypeDictionaryKeyCallBacks,
        &kCFTypeDictionaryValueCallBacks
    );

    return font;
}

QuFont *QuFontButtonA()
{
    CTFontRef ct_font = CTFontCreateUIFontForLanguage(
        kCTFontUIFontPushButton,
        0,
        NULL
    );
    return _QuFontA_ct_font(ct_font);
}

QuFont *QuFontA(char *name, float size)
{
    CFStringRef cf_name;
    CTFontRef ct_font;

    cf_name = CFStringCreateWithCString(
        kCFAllocatorDefault,
        name,
        kCFStringEncodingUTF8
    );
    ct_font = CTFontCreateWithName(
        cf_name,
        size,
        NULL
    );
    CFRelease(cf_name);

    if (!ct_font)
        qui_die("font not found");

    return _QuFontA_ct_font(ct_font);
}

void font_free(QuFont *font)
{
    CFRelease(font->_font);
    CFRelease(font->_attrs);
    free(font);
}
