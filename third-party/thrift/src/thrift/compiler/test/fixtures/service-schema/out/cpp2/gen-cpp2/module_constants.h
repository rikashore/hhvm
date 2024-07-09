/**
 * Autogenerated by Thrift for thrift/compiler/test/fixtures/service-schema/src/module.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated @nocommit
 */
#pragma once

#include <thrift/lib/cpp2/gen/module_constants_h.h>

#include "thrift/compiler/test/fixtures/service-schema/gen-cpp2/module_types.h"

namespace cpp2 {
namespace module_constants {

  constexpr std::string_view _fbthrift_schema_{"\031\354\034\030\006module\000\026\366\360\235\362\253\251\334\326w\031&\265\323\207\243\235\265\321\345P\274\276\333\332\305\273\252\376\233\001Y8\020~\203T\344\20103\365#r\010\271\346\261\322K\020\313n7\247\375Z\272\031\363\020\030%\301\306$_\020\240\311\3732\362\247\347(\033w7\344\337#\215&\010\n>thrift/compiler/test/fixtures/service-schema/src/module.thrift+\001\210\njava.swift\034test.fixtures.service_schema\000\034\030\006thrift\030\036facebook.com/thrift/annotation\000\026\265\323\207\243\235\265\321\345P\031\026\272\333\377\265\360\206\313\204\031Y\370\021\020\254i0A\300y+\320@f\026\370l\277v\247\020p\032f3h\036\313s\244C\340\275\221C\261\372\020\272\346\262z\221v\325&\270\250\273\351\370\313Zc\020>\274\001\302\304\317\214\n\223\374F@\204\227\0203\020\303g\210\344\212\373\327a\"\025\236mO\346\016\237\020\245?\000\334\301\271\036\227\017Z\245\nULDh\020\230\361\261\344}\244D\212xK\364\301\207\377\324\355\020\305\305\264\310\010\216(\357/\307}\264?\314?\246\020\014\"\255^\017 \010Ahh:\266\022\332\361\275\020S\301\267\032\277\233\354 \367\032Y7E\252\277\007\020\267\014\321n\336\355\246k\313\271\211\267=\026\271\020\020W\314\234Bl\275`\316\365\254&\240\0179\264\014\020\362@i\313\207w\335qFm4J\3019BJ\020N\341\242E\307,\314\023\364\316\342\350AxY\357\020e\321\016\337t\234\254\223\222\247G\211+\025L2\020\346\374\277\306\030\345\177\025\003\201,(|\016\210-\020\367!]\0146\203\005\253\261\320\375\000>\343h-\010\n\037thrift/annotation/thrift.thrift+\006\210\007android)com.facebook.thrift.annotation_deprecated\002go\030thrift.annotation.thrift\004java)com.facebook.thrift.annotation_deprecated\002js\030thrift.annotation.thrift\002py\030thrift.annotation.thrift\npy.asyncio)facebook_thrift_asyncio.annotation.thrift\000\034\030\005scope\030\036facebook.com/thrift/annotationL\030\205\003Annotations that indicate which IDL definition a structured annotation can\nbe placed on.\n\nFor example:\n  include \"thrift/annotation/scope.thrift\"\n\n  @scope.Struct\n  struct MyStructAnnotation {...}\n\n  @MyStructAnnotation // Good.\n  struct Foo{\n    @MyStructAnnotation // Compile-time failure. MyStructAnnotation is not\n                        // allowed on fields.\n    1: i32 my_field;\n  }\n\034\026\272\333\377\265\360\206\313\204\031\025&\025\002\025F\025\010\000\000\000\026\272\333\377\265\360\206\313\204\031i\370\021\020j\346\374\233\360\252\236\317\341.\305\300\363;l\362\020\014\352\342\307\036\334\177\037'\252\220\373\231~\347\305\020Rf\030\244{;\314\365\002A\340\0315xNG\020\220\256\277\241\243\356\007\300\302\026\177Ky\364\234W\020\321\305CP\305}B\214+\215\242\221\377u\314\314\020V\351\223\032s\036\245\236\372\367w\322\252\355\366\325\020k<\365\367\256\3106*\031\310\256{\274\332\223\000\0205'\\\313\256\311h\317\024\017\312=\000\301[\027\020\244\230\264?\n*\362\231\371\233O\342\201~\nl\020\216@\254\215[\3006\317z\010\355\003.\252B8\020\377\327\352\2527\003\036=N\340\250-\301U\213z\020(%\250\020\242k\207\311vE\223;\314\226\210f\020F\334\365T08\241U\302,\004\033\314\023+\344\020%\376!~\024\3034\241\325\220\371G\253/\011\010\020\364\216\256\222<\037\n\247\254\000\212\333\241f\034\275\020u\357M%\256G\322\321\3508\346\014>\3779m\020y2\2174\317z\035\n\233\217\rh\242C\325\022\010\n\036thrift/annotation/scope.thrift+\006\210\007android)com.facebook.thrift.annotation_deprecated\002go\027thrift.annotation.scope\004java)com.facebook.thrift.annotation_deprecated\002js\027thrift.annotation.scope\002py\027thrift.annotation.scope\npy.asyncio(facebook_thrift_asyncio.annotation.scope\000\034\030\006schema\030\030facebook.com/thrift/typek\002\214+facebook.com/thrift/annotation/Experimental\000)facebook.com/thrift/annotation/TerseWrite\000\014\014\030\240\005The canonical representations for a Thrift schema.\n\nThe definitions in this file contain the absolute minimal amount of\ninformation needed to work with a 'dynamic' thrift value (e.g., one where the\ntype is only known at runtime).\n\n\nNote that, while an AST representation may reuse some of the definitions from\nthis file, it has significantly different design goals. For example, an ideal\nAST representation is a ~pure representation of the source file, with as\nlittle 'interpretation' as possible. While a 'schema' is the result of\nperforming semantic analysis on an AST, to distill the result of interpreting\nthe source file in to the representations found in this file.\n\034\026\274\276\333\332\305\273\252\376\233\001\0254\025\002\025P\025\010\000\000\000\026\274\276\333\332\305\273\252\376\233\001\031\206\332\212\275\376\260\222\277\244\366\001\217\302\234\207\347\245\301\362\254\001\265\323\207\243\235\265\321\345P\336\236\374\323\317\254\331\244v\305\350\251\336\361\302\360\224'\346\224\367\371\374\233\307\327\213\001\250\273\302\303\253\375\277\342U\276\334\225\315\205\323\320\240\037Y\370-\020\343\020%\000\031\037\227WS\305Y\274\332[+\302\020|o@\037j\271_!\377\373\371!\266\327\332\236\020\177\266\253K\347\306\242\004,\021\331\225R\370\304\335\020\024H\317F\007*\354\350\220\034\030iW\037\207f\020X\031\347B \341#\016\332\034\346\353\325\337\033\205\020\370zom\342K\317\023\314'\223\357\211T\002(\020e\322\315\270\235\034)=\202\367\3360\307\230\215\351\020\315}\355\177j\357\204\034'\023\335[\231)K\352\020\351W@\177Z\022\242\027\362\3771q\030\211\200\334\020{\217\272\013=\262\010\360\200\301\036\307\033\310z\013\020 \266\366\213\232\030\027\025}WD\356+c\331l\020}\335(\327\211\033\3716K\310\231e?\001\243\362\0207 \016d8[1\225g\332B\3449\264\025H\020\003\\\310\177\224\277\202\266`\023\002\371\325\374\207\231\020\241\016\271\336\267\353\357\364\036`\275\274\017N\377\272\020\317\317`S\366\226f\201\023\377\022\356\263my\355\020V\224U\010\234\350!3\362\267O+\275\322\352\217\020\036\324y\035\330\365\316\366\337\216\202\327\215\255\376\345\020}!\234pohB\304d^\332\217\017b6\231\020\360\327L\357 \233\232\355\352\204\273!\261\027\376)\020W\311\317\342\307\0145\010k\264\373\255\243\324p]\020JYF\275\024\231\311@\n2Bl\301\"\245\321\020\266\202\247Pe\345\332]\350\274\002n!.\255]\020\366q\016k\257\027\217\230\373\226\343\022Ae\334;\020\334\202\370k\022\345\263\023\374\375\301Yx\200\337w\020\341g*\037\205)?\027\243a0lI\021\346\016\020}\204W\\m^\275\342\025^\317R\332n<\204\020\020O\367\001>\326\320c\032\363\274y\321\256|\366\020\300\315\324\223d\253O\313\3214M\235\254\253G\247\020{\336t\375n'\215\372[`\277\2028\205\024\021\020\230\303\242\235\363\225\0327:\332\370F\214\353\260=\02015\310\030\230\354Uc\346(\006O\007\250z\235\020\006V\314tK\024\230+O\377b\013~\212\010T\020\335\266mKwtq\335~\251\226\366O\244\007\240\0201\327\277!\037\214f\r\352\245\306 \330\022\025\373\020\237i\374e\257\270\313ce\216\210\222L\342\304\266\020Z9b\337\255,]\217\231\372<\020\372\034\340w\020\202\034\220\250\035\246;j\327\037\206\334\240\312G\316\020%\323\325\217\230\326\304\227\026\202\235\200\315k\263\204\020#x\314\331\365\344\006\211\326\211\371\303|l\3711\020\240\001zv\336\262\005\377(\203v\036De^C\020\007\034\363\215P_\377[\025o\201\330\250\346\263\374\020~\332hL\365R\235=\346\342\204(\0229\230\032\020\243qd\236\240\236\263\372\364=\203\326O\352\335\341\020\017\000\023\341V!Q\232\377v\367~\231\250sM\010\n\037thrift/lib/thrift/schema.thrift+\004\210\004cpp2\022apache.thrift.type\002go\030thrift.lib.thrift.schema\njava.swift\030com.facebook.thrift.type\003py3\022apache.thrift.type\000\034\030\004hack\030#facebook.com/thrift/annotation/hack\000\026\332\212\275\376\260\222\277\244\366\001\031\026\272\333\377\265\360\206\313\204\031Y\250\020q\242\017f\336\315z+_?\302\314\202\321\332\330\020\310-\361\245\272+\254\262\335\362\210\2264\234\233\370\020\322\236\222PhgC4\227\311B\177\341\355$k\020l7\216\301`\252j\337\032h\216\266\243\020\001\004\0207\205`\310\230C\332\372\025s\243\257\301\024\377T\020<\330\2219\311\231N\361\324\267\366\336uT\2512\020<lS-\242\212\337\254um\374\037\233'\223\027\020\354\276l\372n\024\260m_\342\025\327\245:'\244\02032\010SC\326\360\352\002Z\355:|\227\305x\020\236\231:|\222\256fx\237\204\340o\240N\375`\010\n\035thrift/annotation/hack.thrift+\006\210\007android.com.facebook.thrift.annotation.hack_deprecated\002go\026thrift.annotation.hack\003hs2\037facebook.thrift.annotation.hack\004java.com.facebook.thrift.annotation.hack_deprecated\002py\026thrift.annotation.hack\npy.asyncio'facebook_thrift_asyncio.annotation.hack\000\034\030\003cpp\030\"facebook.com/thrift/annotation/cpp\000\026\217\302\234\207\347\245\301\362\254\001\031&\272\333\377\265\360\206\313\204\031\265\323\207\243\235\265\321\345PY\370\024\020\276\312\010\337v\230(D\"\273\226SA6Q-\020\365\215\024\313\305\022Z\301v{ax\003\300[/\020\227\232\312\341\325^WT\354\177oI\036{\262\314\020\273\326\001}\002\213\216\225\335o\267\327\"\023\346\213\0203:\345\216d\227\277\002\026s\261r\032^\236\345\020\300U&\354\366\0309w\246\272_\025\305n\257\242\020\312]\016\301}\324\306\270D\361t?\310W\363\236\020\325\234-\030\220\011\303\324\316P\010/\304\342\230\312\020[0\237\270\344\207\353\230\355\021\206n3d\002m\020f\367'\233\275\025\325O\323\263j\276\302\214\337g\020\305\202\004QB\2273\257\273\324^\273\346\256\222\365\020\243\030\274\306\245\202\265\226\267\343+Y=\0277\352\020\034Og\355\357\246\210\242\364\354;\362\200_\301\227\020\226;\325h\242\2570\330\227\227\035h\020C#\261\020\323b\024F\241?\221v\324\345\246\367L\023\215\374\020\"0\016}\261\363D\002\206\206\247-\217\254\237\370\0203\205\022\002\274\217\351g0s\202I\001\335\021\264\020\313\225\010s\332\335\326\324_\026\2041\230\270B\326\020\217\340\\E\266\337`?\351\027L\312r\022\230p\020\321;5ni\022\246\267\363\003a\241}\275\261\252\010\n\034thrift/annotation/cpp.thrift+\006\210\007android-com.facebook.thrift.annotation.cpp_deprecated\002go\025thrift.annotation.cpp\004java-com.facebook.thrift.annotation.cpp_deprecated\002js\025thrift.annotation.cpp\002py\025thrift.annotation.cpp\npy.asyncio&facebook_thrift_asyncio.annotation.cpp\000\034\030\002id\030\030facebook.com/thrift/typek\002\214+facebook.com/thrift/annotation/Experimental\000)facebook.com/thrift/annotation/TerseWrite\000\000\026\336\236\374\323\317\254\331\244v\031&\217\302\234\207\347\245\301\362\254\001\265\323\207\243\235\265\321\345PY\230\020i\007\000[\267x\251\002q\317\007\203\277]P\260\020\027\341\031\246\372Q0\276\205\375\0354\027\236Q\257\020\362\2461t\006\016\241\\\373\001\000\377\363\372\253\341\020\267\345\337|\335'\311\024\245\016\026\207\n|\027\323\020\337H\365\320\317i`J\362\265\321\340\235M\001\350\020\300\205\240\206\206\232FI\327I\326\266\250\006\243\221\020\306\360\260]\344\221\276\355\223lsD\347.Z)\020\034>\3630q\374\250\377@\003\022\207n\332Y\222\020\251\226\021>F3;\245\310\345\365\227\010\205\364\016\010\n\033thrift/lib/thrift/id.thrift\033\001\211\003cpp\030\035thrift/lib/thrift/detail/id.h\033\011\210\004cpp2\022apache.thrift.type\002go\024thrift.lib.thrift.id\004java\030com.facebook.thrift.type\njava.swift\033com.facebook.thrift.type_id\002js\022apache.thrift.type\003php\025apache_thrift_type_id\002py\024thrift.lib.thrift.id\npy.asyncio\030apache_thrift_asyncio.id\003py3\022apache.thrift.type\000\034\030\010standard\030\030facebook.com/thrift/typek\002\214+facebook.com/thrift/annotation/Experimental\000)facebook.com/thrift/annotation/TerseWrite\000\014\014\030;The **standard** types all Thrift implementations support.\n\034\026\305\350\251\336\361\302\360\224'\0250\025\002\0250\025\204\001\000\000\000\026\305\350\251\336\361\302\360\224'\0316\265\323\207\243\235\265\321\345P\215\323\200\221\364\345\334\347R\217\302\234\207\347\245\301\362\254\001Yh\020\257bs\326\311\254\236\263\023\017\034\323f\372b\206\020Vv\342\361\331fF\030\360 \306\344C\325\333\027\020\265\014l'Yo\253yG\233H\275\207\0211L\020\344\242\254\014}t\013\375\215{$\216~s>8\020\3108\304\220\007\350R'\213\025\361\346\002\216\227\036\020\274\203)\232O\231\342\241\262\243\342\357S\225l\210\010\n!thrift/lib/thrift/standard.thrift\033\001\211\003cpp(\022<folly/io/IOBuf.h>\022<folly/FBString.h>\033\011\210\004cpp2\022apache.thrift.type\002go\032thrift.lib.thrift.standard\004java\030com.facebook.thrift.type\njava.swift!com.facebook.thrift.standard_type\002js\022apache.thrift.type\003php\033apache_thrift_type_standard\002py\032thrift.lib.thrift.standard\npy.asyncio\036apache_thrift_asyncio.standard\003py3\022apache.thrift.type\000\034\030\004java\030#facebook.com/thrift/annotation/java\000\026\215\323\200\221\364\345\334\347R\031\026\272\333\377\265\360\206\313\204\031Yx\020\205\"\027;\310\350\3622\313\376<@O^\014\342\020u\356V\307j!F\305\272\233yB\004\270q\037\020\241\274'<>.\033\247j\000\252\001\273\023U\034\020e\376\210A\345\003<\246\272\014\316\n\355\375\371,\020\326\023\027\230A\321P=\341\027\344Uy\002\240}\020\233\002Cu\335\024f\372\243[bY\"\216T{\020\"\036B\360\036w$\214!\311P4\3223r\031\010\n\035thrift/annotation/java.thrift+\006\210\007android.com.facebook.thrift.annotation.java_deprecated\002go\026thrift.annotation.java\004java.com.facebook.thrift.annotation.java_deprecated\002js\026thrift.annotation.java\002py\026thrift.annotation.java\npy.asyncio'facebook_thrift_asyncio.annotation.java\000\034\030\010protocol\030\034facebook.com/thrift/protocolk\001\214+facebook.com/thrift/annotation/Experimental\000\000\026\346\224\367\371\374\233\307\327\213\001\031v\217\302\234\207\347\245\301\362\254\001\265\323\207\243\235\265\321\345P\336\236\374\323\317\254\331\244v\324\240\271\253\217\372\215\366\357\001\250\273\302\303\253\375\277\342U\305\350\251\336\361\302\360\224'\276\334\225\315\205\323\320\240\037YX\020L\274I'\022\224\232J\362\2341\263\246.\304\215\020\220\006@+\341\006\221\251\202\377\265\\\352\0073\225\020\300\324\342\213r`\256\221\026\311@\201o\305\355\230\020\363T\000Cl\335@\2271L3\250\014#\344\255\020g\305\031\021DO\277eQI\276/\030>\326w\010\n!thrift/lib/thrift/protocol.thrift\033\001\211\003cpp(\030folly/container/F14Map.h\035thrift/lib/thrift/detail/id.h\033\007\210\004cpp2\026apache.thrift.protocol\002go\032thrift.lib.thrift.protocol\njava.swift\"com.facebook.thrift.protocol_swift\003php\026apache_thrift_protocol\002py\032thrift.lib.thrift.protocol\npy.asyncio\036apache_thrift_asyncio.protocol\003py3\026apache.thrift.protocol\000\034\030\017protocol_detail\030#facebook.com/thrift/protocol/detailk\001\214+facebook.com/thrift/annotation/Experimental\000\000\026\324\240\271\253\217\372\215\366\357\001\031F\265\323\207\243\235\265\321\345P\305\350\251\336\361\302\360\224'\217\302\234\207\347\245\301\362\254\001\332\212\275\376\260\222\277\244\366\001YH\020\330\200`\241s\344\241\250\374\211~\352-!\250*\020u~\004-\220O\314\3749rW%\305tI\274\020\244\355\270\034U\023s\217\204\350\232V^\225\231\321\020\240?\304\370\331\271\212\021\215\374c\016\310\231\334\334\010\n(thrift/lib/thrift/protocol_detail.thrift\033\001\211\003cpp8#thrift/lib/thrift/detail/protocol.h\030folly/container/F14Map.h\030folly/container/F14Set.h\033\007\210\004cpp2\035apache.thrift.protocol.detail\002go!thrift.lib.thrift.protocol_detail\njava.swift)com.facebook.thrift.protocol_detail_swift\003php\035apache_thrift_protocol.detail\002py!thrift.lib.thrift.protocol_detail\npy.asyncio%apache_thrift_asyncio.protocol_detail\003py3\035apache.thrift.protocol.detail\000\034\030\004type\030\030facebook.com/thrift/typek\002\214+facebook.com/thrift/annotation/Experimental\000)facebook.com/thrift/annotation/TerseWrite\000\014\014\0307Canonical representations for well-known Thrift types.\n\034\026\250\273\302\303\253\375\277\342U\0254\025\002\0254\025|\000\000\000\026\250\273\302\303\253\375\277\342U\031F\217\302\234\207\347\245\301\362\254\001\332\212\275\376\260\222\277\244\366\001\265\323\207\243\235\265\321\345P\342\205\302\367\252\232\357\202\024YX\020\367\324tY\263u9E)\335mFs5b\025\020h\026\341%6^\010n\016\333P\215a\354\363i\020\335pk\316\251\332\002\220\204\312\221\011\320\n\330g\020\232VQ\265R\002x;v\202\330n/\017\303f\020\366\030\304\336\310\036\340\247\033\247*\371Ew\361v\010\n\035thrift/lib/thrift/type.thrift\033\001\211\003cpp8!<thrift/lib/cpp2/type/BaseType.h>!<thrift/lib/cpp2/type/Protocol.h>\035<thrift/lib/cpp2/type/Type.h>\033\007\210\004cpp2\022apache.thrift.type\002go\026thrift.lib.thrift.type\njava.swift\036com.facebook.thrift.type_swift\003php\022apache_thrift_type\002py\026thrift.lib.thrift.type\npy.asyncio\032apache_thrift_asyncio.type\003py3\022apache.thrift.type\000\034\030\010type_rep\030\030facebook.com/thrift/typek\001\214+facebook.com/thrift/annotation/Experimental\000\014\014\030\204\003The **underlying representations** for well-known Thrift types.\n\nThe following definitions are provided as unadapted underlying\nrepresentations for 'public' adapted typedefs defined in 'type.thrift'.\n\nThese definitions are named after their representations, using the form\n'{name}{Type}. For example, for a 'public' exception `Foo`, the underlying\ntype would be `exception FooException`.\n\034\026\342\205\302\367\252\232\357\202\024\025,\025\002\025>\025\010\000\000\000\026\342\205\302\367\252\232\357\202\024\031F\265\323\207\243\235\265\321\345P\336\236\374\323\317\254\331\244v\305\350\251\336\361\302\360\224'\276\334\225\315\205\323\320\240\037Y(\020n4g\2039Y\340Ck\224\224\260\020\370\264\000\020\332\342U\347^R\371\017\305\342\020\034\245\011c\020\010\n!thrift/lib/thrift/type_rep.thrift+\010\210\004cpp2\022apache.thrift.type\002go\032thrift.lib.thrift.type_rep\njava.swift\036com.facebook.thrift.type_swift\002js\022apache.thrift.type\003php\026apache_thrift_type_rep\002py\032thrift.lib.thrift.type_rep\npy.asyncio\036apache_thrift_asyncio.type_rep\003py3\022apache.thrift.type\000\034\030\006python\030%facebook.com/thrift/annotation/python\000\026\276\334\225\315\205\323\320\240\037\031\026\272\333\377\265\360\206\313\204\031YX\020\331\342\023\227\355\373\333\220\355\353NU\257\007\340\267\020\327\235\222\275\033g\313\005\301J\227G\024'\372\322\020)|\376e\234Gk\350B\231\307\345Ko\351K\020\335\235\251\001\020\267\312*\024k\350\317#\316\243!\020\340\325\354\366\316n\n\177\030\221%\3730\322\326\010\010\n\037thrift/annotation/python.thrift+\005\210\007android0com.facebook.thrift.annotation.python_deprecated\002go\030thrift.annotation.python\004java0com.facebook.thrift.annotation.python_deprecated\002py\030thrift.annotation.python\npy.asyncio)facebook_thrift_asyncio.annotation.python\000+\001l\333\357\225\212\364\230\255\345\236\001E\002\000[\003\214\020~\203T\344\20103\365#r\010\271\346\261\322KL\034\030\006Resultl\026\366\360\235\362\253\251\334\326w\025,\025\002\0254\025\004\000\000\031<\034\030\002OKl\026\366\360\235\362\253\251\334\326w\025.\025\006\025.\025\024\000\000\000\034\030\005SO_SOl\026\366\360\235\362\253\251\334\326w\0250\025\006\0250\025\032\000\000\025\002\000\034\030\004GOODl\026\366\360\235\362\253\251\334\326w\0252\025\006\0252\025\030\000\000\025\004\000\000\000\020\240\311\3732\362\247\347(\033w7\344\337#\215&|\034\030\021PrimitivesService{\001\2144facebook.com/thrift/annotation/GenerateRuntimeSchema\000\014\016\026\366\360\235\362\253\251\334\326w\025B\025\002\025L\025\004\000\000\031<<\030\004initl\026\366\360\235\362\253\251\334\326w\025F\025\006\025F\025T\000\000\034\031,\024\002,\034U\000\000\031\014\000\034\030\006param0\000\000\024\004,\034U\000\000\031\014\000\034\030\006param1\000\000\000,\034U\000\000\031\014\000\000<\030\022method_that_throwsl\026\366\360\235\362\253\251\334\326w\025H\025\006\025H\025z\000\000)\034\024\002,\034\334(\020\313n7\247\375Z\272\031\363\020\030%\301\306$_\000\000\031\014\000\034\030\001e\000\000\034\034\254(\020~\203T\344\20103\365#r\010\271\346\261\322K\000\000\031\014\000\000<\030\022return_void_methodl\026\366\360\235\362\253\251\334\326w\025J\025\006\025J\025L\000\000\034\031\034\024\002,\034U\000\000\031\014\000\034\030\002id\000\000\000,\034\000\031\014\000\000\000\000\020\313n7\247\375Z\272\031\363\020\030%\301\306$_<\034\030\017CustomExceptionl\026\366\360\235\362\253\251\334\326w\0258\025\002\025>\025\004\000\000\031,\024\002,\034\205\000\000\031\014\000\034\030\004namel\026\366\360\235\362\253\251\334\326w\025:\025\006\025:\025$\000\000\000\024\004,\034\254(\020~\203T\344\20103\365#r\010\271\346\261\322K\000\000\031\014\000\034\030\006resultl\026\366\360\235\362\253\251\334\326w\025<\025\006\025<\025F\000\000\026\333\357\225\212\364\230\255\345\236\001\000\000\000\000", 10609};
  constexpr std::string_view _fbthrift_schema() {
    return _fbthrift_schema_;
  }


} // namespace module_constants
} // namespace cpp2
