﻿#ifndef FUANDA_QRY_ORDER_HANDLER_H
#define FUANDA_QRY_ORDER_HANDLER_H
////////////////////////////////////////////////////////////////////////////////
#include "Server.h"

namespace serverframe{;
////////////////////////////////////////////////////////////////////////////////
class QryOrderHandler : public RequestHandler
{
////////////////////////////////////////////////////////////////////////////////
public:
public:
	void OnRequest(IN AmqContext& context);
};


////////////////////////////////////////////////////////////////////////////////
}// serverframe
#endif