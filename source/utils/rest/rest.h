/*
 * rest.h
 *
 *  Created on: 19 de set de 2017
 *      Author: dkrepsky
 */

#ifndef SOURCE_UTILS_REST_REST_H_
#define SOURCE_UTILS_REST_REST_H_

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

typedef enum {
	REST_OK,        //
	REST_MEM,       //
	RES_PARAM,      //
	REST_UNKNOWN,   //
} RestErr;

typedef enum {
	GET,      //
	POST,     //
	PUT,      //
	PATCH,    //
	DELETE,   //
	COPY,     //
	HEAD,     //
	OPTIONS,  //
	LINK,     //
	UNLINK,   //
	PURGE,    //
	LOCK,     //
	UNLOCK,   //
	PROPFIND, //
	VIEW,     //
} RestType;

typedef enum {
	AUTH_NONE,    //
	AUTH_BASIC,	  //
} AuthType;

typedef enum {
	CONTENT_JSON, //
	CONTENT_XML,  //
	CONTENT_RAW,  //
} ContType;

typedef enum {
	NO_CACHE,	    //
	NO_STORE,	    //
	NO_TRANSFORM,	//
	ONLY_IF_CACHED,	//
} CacheControl;

typedef struct {
	char *user;
	char *passwd;
} AuthBasic;

typedef struct {
	char *host;
	uint16_t port;
	char *url;
	char *param;
	char *body;
	AuthType authType;
	void *auth;
	RestType restType;
	ContType contType;
	CacheControl cacheCtrl;
	uint16_t contLenght;
} Request;

typedef struct {
	uint16_t status;
	char *body;
} Response;

void rest(Request *req, Response *resp);

#endif /* SOURCE_UTILS_REST_REST_H_ */
