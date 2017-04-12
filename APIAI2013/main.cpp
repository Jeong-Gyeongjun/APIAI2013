
#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <string>
#include <locale>
#include <codecvt>

#include <future>
#include <thread>
#include <functional>

#include <apiai/io/StreamReader.h>

#include <apiai/AI.h>
#include <apiai/query/TextQueryRequest.h>
#include <apiai/query/request/QueryText.h>
#include <apiai/exceptions/Exception.h>
#include <apiai/exceptions/JSONException.h>

using namespace std;
using namespace ai::query::request;


int main()
{
	ai::AI::global_init();

	auto credentials = ai::Credentials("1ea86ba26bf34a7197b1e25c2daee0f3 ");

	auto params = Parameters("sessionId").setResetContexts(true);

	wstring a = L"³»ÀÏ³¯¾¾";

	std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>, wchar_t> convert;

	std::string utf8_string = convert.to_bytes(a);

	auto request = std::shared_ptr<TextQueryRequest>(new TextQueryRequest(QueryText::One(utf8_string), "ko", credentials, params));

	try {
		std::cout << request->perform() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	ai::AI::global_clean();

	system("pause");
	return 0;
}