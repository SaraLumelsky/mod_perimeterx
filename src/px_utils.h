#ifndef PX_UTILS_H
#define PX_UTILS_H

#include <http_protocol.h>
#include <apr_pools.h>

#include "px_types.h"

struct response_t {
    char* data;
    size_t size;
    server_rec *server;
    const char *app_id;
};

const char *get_request_ip(const request_rec *r, const px_config *conf);
int extract_payload_from_header(apr_pool_t *pool, apr_table_t *headers, const char **payload3, const char **payload1);
CURLcode post_request_helper(CURL* curl, const char *url, const char *payload, long timeout, px_config *conf, server_rec *server, char **response_data);
int escape_urlencoded(char *escaped, const char *str, apr_ssize_t slen, apr_size_t *len); 
#endif
