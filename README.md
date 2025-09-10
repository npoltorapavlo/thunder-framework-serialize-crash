```shell script
PATH=${PWD}/install/bin:${PATH} \
LD_LIBRARY_PATH=${PWD}/install/lib:${LD_LIBRARY_PATH} \
gdb -ex=run thunder-framework-serialize-crash
# Program received signal SIGSEGV, Segmentation fault.
# 0x000055555555c8b5 in Thunder::Core::JSON::String::Serialize (this=0x555555582d28, 
#     stream=0x7fffffffd4f0 "0\\u0000\\u0000\\u0000\\u0000\\u0000\\u0000\\u0000\\u0000\\u0000\\u0000\\u0000\\u0000\\u0000\\u0000\\u0000\\u0000\\u0000\\u0000\\u0000\\u0000\\u0000\\u0000\\u0000\\u0000\\u0000\\u0000\\u0000\\u0000\\u0000\\u0000\\u0000\\u0000\\u0000\\"..., maxLength=1024, offset=@0x7fffffffd26c: 135833)
# 1833	                        const uint16_t current = static_cast<uint16_t>((_value[offset - 1]) & 0xFF);
(gdb) bt
#0  Thunder::Core::JSON::String::Serialize
#1  Thunder::Core::JSON::Container::Serialize
#2  Thunder::Core::JSON::IElement::ToString<Thunder::Core::JSON::IElement>
#3  Thunder::Core::JSON::IElement::ToString
```

when serializing non-printable (e.g from uninitialized), the line in framework:
https://github.com/rdkcentral/Thunder/blob/1e31db1cb52b4ebabe1aad6cfc5d65a9b2c9fb33/Source/core/JSON.h#L1927

causes overflow (length is 1, skip is 6, result is 4294831474).