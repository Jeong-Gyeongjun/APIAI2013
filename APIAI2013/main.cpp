
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
#include <apiai/query/response/Fulfillment.h>


#include <atlcore.h>

using namespace std;
using namespace ai::query::request;


int main()
{
	ai::AI::global_init();

	auto credentials = ai::Credentials("1ea86ba26bf34a7197b1e25c2daee0f3 ");

	auto params = Parameters("sessionId").setResetContexts(true);
	
	while (true)
	{
		std::string input;
		cin >> input;

		USES_CONVERSION;
		wstring w_input = A2W(input.c_str());
		std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>, wchar_t> convert;
		std::string utf8_input = convert.to_bytes(w_input);


		auto request = std::shared_ptr<TextQueryRequest>(new TextQueryRequest(QueryText::One(utf8_input), "ko", credentials, params));

		try {
			std::cout << request->perform() << std::endl;
			//std::cout << request->perform().result.getFulfillment()->getSpeech() << std::endl;
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}

		ai::AI::global_clean();
	}

	system("pause");
	return 0;
}