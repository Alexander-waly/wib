#include "sapi/embed/php_embed.h"
#include <emscripten.h>
#include <stdlib.h>

int EMSCRIPTEN_KEEPALIVE pib_eval(char *code) {
    int ret = 0;
    zend_error_handling error_handling;

    zend_replace_error_handling(EH_THROW, NULL, &error_handling TSRMLS_CC);
    putenv("USE_ZEND_ALLOC=0");
    PHP_EMBED_START_BLOCK(0, NULL)
        ret = zend_eval_string_ex(code, NULL, "WIB", 1);
    PHP_EMBED_END_BLOCK()
    return ret;
}
