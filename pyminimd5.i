%module minimd5
%{
extern char *md5sum(const char *const file);
%}

extern char *md5sum(const char *const file);

