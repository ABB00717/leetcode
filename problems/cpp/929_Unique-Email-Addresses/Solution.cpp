#include <string>
#include <string_view>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
private:
  string getValidLocalName(string_view email) {
    string localName = "";

    for (auto ch : email) {
      if (ch == '@' || ch == '+')
        break;
      if (ch != '.')
        localName.push_back(ch);
    }

    return localName;
  }

  string getValidDomainName(string_view email) {
    string domainName = "";
    size_t pos = email.find('@');
    if (pos != string::npos)
      domainName = email.substr(pos + 1);

    return domainName;
  }

public:
  int numUniqueEmails(vector<string> &emails) {
    std::unordered_set<string> validEmails;
    validEmails.reserve(emails.size());

    for (const auto &email : emails) {
      string_view emailView(email);
      string localName = getValidLocalName(emailView);
      string domainName = getValidDomainName(emailView);

      string validEmail;
      validEmail.reserve(localName.length() + domainName.length() + 1);
      validEmail.append(localName).append("@").append(domainName);

      validEmails.emplace(std::move(validEmail));
    }

    return validEmails.size();
  }
};
