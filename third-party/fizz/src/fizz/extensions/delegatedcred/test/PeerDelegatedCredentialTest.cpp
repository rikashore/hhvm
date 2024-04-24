/*
 *  Copyright (c) 2019-present, Facebook, Inc.
 *  All rights reserved.
 *
 *  This source code is licensed under the BSD-style license found in the
 *  LICENSE file in the root directory of this source tree.
 */

#include <folly/portability/GMock.h>
#include <folly/portability/GTest.h>

#include <fizz/crypto/Utils.h>
#include <fizz/crypto/test/TestUtil.h>
#include <fizz/extensions/delegatedcred/PeerDelegatedCredential.h>
#include <fizz/protocol/clock/test/Mocks.h>

using namespace folly;

using namespace testing;
using namespace fizz::test;

namespace fizz {
namespace extensions {
namespace test {

// @lint-ignore-every PRIVATEKEY

/*
 *  Randomly generated ECDSA-P256 private key
 *  Command: openssl ecparam -name secp256r1 -genkey
 *  Output: Randomly generated ECDSA-P256 private key
 */
StringPiece kP256CredCertKey = R"(
-----BEGIN PRIVATE KEY-----
MIGHAgEAMBMGByqGSM49AgEGCCqGSM49AwEHBG0wawIBAQQgOe/v6hxwTP9uA5dE
se5CO6ARqeOYXEy1ede9eRCmDduhRANCAATsRtkwp2zrkRhyJpJQsUfjBkq385OG
JQvi5Bb1zJuvYcjMrrxyis4kJ4dc6xXeWlhLjpvf1IFmvUZmmsUcfmAd
-----END PRIVATE KEY-----
)";

// clang-format off
/*
 *  Delegated credential certificate generated by kP256CredCertKey
 *  Prerequisites:
 *    - P133567922 in config.cfg
 *    - kP256CredCertKey in p256_key.pem
 *  Command: openssl req -new -key p256_key.pem -x509 -nodes -days 365 -config config.cfg
 *  Output: Self-signed delegation certificate
 */
// clang-format on
StringPiece kP256CredCert = R"(
-----BEGIN CERTIFICATE-----
MIICKzCCAdGgAwIBAgIJAPi2vMRfOVd0MAoGCCqGSM49BAMCMGIxCzAJBgNVBAYT
AlhYMRUwEwYDVQQHDAxEZWZhdWx0IENpdHkxHDAaBgNVBAoME0RlZmF1bHQgQ29t
cGFueSBMdGQxHjAcBgNVBAMMFXJldnByb3h5LWRlbGVnYXRlZC1lYzAgFw0xOTA5
MjMwMjAyMzVaGA8yMTE5MDgzMDAyMDIzNVowYjELMAkGA1UEBhMCWFgxFTATBgNV
BAcMDERlZmF1bHQgQ2l0eTEcMBoGA1UECgwTRGVmYXVsdCBDb21wYW55IEx0ZDEe
MBwGA1UEAwwVcmV2cHJveHktZGVsZWdhdGVkLWVjMFkwEwYHKoZIzj0CAQYIKoZI
zj0DAQcDQgAE7EbZMKds65EYciaSULFH4wZKt/OThiUL4uQW9cybr2HIzK68corO
JCeHXOsV3lpYS46b39SBZr1GZprFHH5gHaNuMGwwHQYDVR0OBBYEFMLkRMB4SclK
8K8uYMQBaYw0gNP7MB8GA1UdIwQYMBaAFMLkRMB4SclK8K8uYMQBaYw0gNP7MAwG
A1UdEwQFMAMBAf8wCwYDVR0PBAQDAgHmMA8GCSsGAQQBgtpLLAQCBQAwCgYIKoZI
zj0EAwIDSAAwRQIgB2EWbwWohYziQ2LmY8Qmn8y0WKR6Mbm5aad0rUBvtK4CIQCv
0U6Z/gFrVr0Cb2kc7M37KD9z5eeTwkQuGqs5GXF8Ow==
-----END CERTIFICATE-----
)";

/*
 *  Randomly generated ECDSA-P256 private key
 *  Command: openssl ecparam -name secp256r1 -genkey
 *  Output: Randomly generated ECDSA-P256 private key
 */
StringPiece kP256DelegatedCredKey = R"(
-----BEGIN EC PARAMETERS-----
BggqhkjOPQMBBw==
-----END EC PARAMETERS-----
-----BEGIN EC PRIVATE KEY-----
MHcCAQEEIA8/keRkilh8bwUPxH9jiP5SsP4QiZtfofayTsRSI59poAoGCCqGSM49
AwEHoUQDQgAE8mV/wDAabnJbPLuF/qd/FMIWHDlrJI97cwq4obtPHyKFF2ukoG+6
/pXOUrEbsIH+/QBpZsnRHjvxryib97Ay+Q==
-----END EC PRIVATE KEY-----
)";

// clang-format off
/*
 *  Delegated credential generated using kP256CredCert, kP256CredCertKey & kP256DelegatedCredKey
 *  Prerequisites:
 *    - kP256CredCert in cert.pem
 *    - kP256CredCertKey in p256_key.pem
 *    - kP256DelegatedCredKey in p256_dc_key.pem
 *  Command: buck run //fizz/tool:fizz -- gendc -cert cert.pem -key p256_key.pem -credkey p256_dc_key.pem | xxd -p
 *  Output: Hex-encoded delegated credential
 */
// clang-format on
StringPiece kP256DelegatedCred{
    "088eb534040300005b3059301306072a"
    "8648ce3d020106082a8648ce3d030107"
    "03420004f2657fc0301a6e725b3cbb85"
    "fea77f14c2161c396b248f7b730ab8a1"
    "bb4f1f2285176ba4a06fbafe95ce52b1"
    "1bb081fefd006966c9d11e3bf1af289b"
    "f7b032f9040300473045022052b6e667"
    "dbaad3b074332834ea1663d2e52ad9fd"
    "38788e028b454844fed71a10022100ea"
    "724cf5014aab5f5804c390d504af1643"
    "743aa58485e16238831229bdc08c11"};

StringPiece kBadP256DelegatedCred{
    "00130914040300005b3059301306072a"
    "8648ce3d020106082a8648ce3d030107"
    "03420004f2657fc0301a6e725b3cbb85"
    "fea77f14c2161c396b248f7b730ab8a1"
    "bb4f1f2285176ba4a06fbafe95ce52b1"
    "1bb081fefd006966c9d11e3bf1af289b"
    "f7b032f90403004630440220302bfeec"
    "446a45b1b37000395c6e15b9c9ff93bc"
    "c405a322ead08e2f970e69110220489e"
    "6825efac5ebe13f2ed8dbca2b5419e58"
    "371f6fe47af04622d6b162d7ebd6"};

// Buffer used for signature/verification
StringPiece kVerifyBuffer{
    "8bc8098c4f45d1c9ea354955f5c99a50b442c6ab8b58c6623582b60ddc8c2ef2"};

// Signature of kVerifyBuffer using kP256DelegatedCred
StringPiece kP256Signature{
    "3045022052b6e667dbaad3b074332834"
    "ea1663d2e52ad9fd38788e028b454844"
    "fed71a10022100ea724cf5014aab5f58"
    "04c390d504af1643743aa58485e16238"
    "831229bdc08c11"};

class PeerDelegatedCredentialTest : public Test {
 public:
  void SetUp() override {
    CryptoUtils::init();
  }

  Buf toBuf(const StringPiece& hex) {
    auto data = unhexlify(hex);
    return IOBuf::copyBuffer(data.data(), data.size());
  }

  DelegatedCredential getCredential(folly::StringPiece dcBuf) {
    Extension ext;
    ext.extension_type = ExtensionType::delegated_credential;
    ext.extension_data = toBuf(dcBuf);
    std::vector<Extension> exts;
    exts.push_back(std::move(ext));
    return *getExtension<DelegatedCredential>(exts);
  }

  void expectThrows(std::function<void()> f, std::string errorStr) {
    std::string what;
    try {
      f();
    } catch (const FizzException& e) {
      what = e.what();
    }

    EXPECT_THAT(what, HasSubstr(errorStr));
  }
};

TEST_F(PeerDelegatedCredentialTest, TestCredentialVerify) {
  auto cred = getCredential(kP256DelegatedCred);
  auto cert = getCert(kP256CredCert);
  auto pubKeyRange = cred.public_key->coalesce();
  auto addr = pubKeyRange.data();
  folly::ssl::EvpPkeyUniquePtr pubKey(
      d2i_PUBKEY(nullptr, &addr, pubKeyRange.size()));

  auto clock = std::make_shared<MockClock>();
  ON_CALL(*clock, getCurrentTime())
      .WillByDefault(Return(std::chrono::system_clock::time_point(
          std::chrono::seconds(1712700000))));
  auto peerCred = std::make_shared<PeerDelegatedCredentialImpl<KeyType::P256>>(
      std::move(cert), std::move(pubKey), std::move(cred));
  peerCred->setClock(clock);

  // We expect all other verification steps to pass and only the final parent
  // cert verifiation to fail
  EXPECT_THAT(
      [&]() {
        peerCred->verify(
            SignatureScheme::ecdsa_secp256r1_sha256,
            CertificateVerifyContext::Server,
            toBuf(kVerifyBuffer)->coalesce(),
            toBuf(kP256Signature)->coalesce());
      },
      ThrowsMessage<std::runtime_error>("Signature verification failed"));
}

TEST_F(PeerDelegatedCredentialTest, TestCredentialVerifyNoExtension) {
  auto cred = getCredential(kP256DelegatedCred);
  auto cert = getCert(kP256Certificate);
  auto pubKeyRange = cred.public_key->coalesce();
  auto addr = pubKeyRange.data();
  folly::ssl::EvpPkeyUniquePtr pubKey(
      d2i_PUBKEY(nullptr, &addr, pubKeyRange.size()));
  auto peerCred = std::make_shared<PeerDelegatedCredentialImpl<KeyType::P256>>(
      std::move(cert), std::move(pubKey), std::move(cred));

  expectThrows(
      [&]() {
        peerCred->verify(
            SignatureScheme::ecdsa_secp256r1_sha256,
            CertificateVerifyContext::Server,
            toBuf(kVerifyBuffer)->coalesce(),
            toBuf(kP256Signature)->coalesce());
      },
      "cert is missing DelegationUsage extension");
}

TEST_F(PeerDelegatedCredentialTest, TestCredentialVerifyBadSignature) {
  // Credential wqas not signed by the right cert
  auto cred = getCredential(kBadP256DelegatedCred);
  auto cert = getCert(kP256CredCert);
  auto pubKeyRange = cred.public_key->coalesce();
  auto addr = pubKeyRange.data();
  folly::ssl::EvpPkeyUniquePtr pubKey(
      d2i_PUBKEY(nullptr, &addr, pubKeyRange.size()));
  auto clock = std::make_shared<MockClock>();
  ON_CALL(*clock, getCurrentTime())
      .WillByDefault(Return(std::chrono::system_clock::time_point(
          std::chrono::seconds(1570400000))));
  auto peerCred = std::make_shared<PeerDelegatedCredentialImpl<KeyType::P256>>(
      std::move(cert), std::move(pubKey), std::move(cred));
  peerCred->setClock(clock);

  expectThrows(
      [&]() {
        peerCred->verify(
            SignatureScheme::ecdsa_secp256r1_sha256,
            CertificateVerifyContext::Server,
            toBuf(kVerifyBuffer)->coalesce(),
            toBuf(kP256Signature)->coalesce());
      },
      "failed to verify signature on credential");
}

TEST_F(PeerDelegatedCredentialTest, TestCredentialVerifyWrongAlgo) {
  auto cred = getCredential(kP256DelegatedCred);
  auto cert = getCert(kP256CredCert);
  auto pubKeyRange = cred.public_key->coalesce();
  auto addr = pubKeyRange.data();
  folly::ssl::EvpPkeyUniquePtr pubKey(
      d2i_PUBKEY(nullptr, &addr, pubKeyRange.size()));
  auto peerCred = std::make_shared<PeerDelegatedCredentialImpl<KeyType::P256>>(
      std::move(cert), std::move(pubKey), std::move(cred));

  // Should fail early due to mismatch with credential
  expectThrows(
      [&]() {
        peerCred->verify(
            SignatureScheme::ecdsa_secp521r1_sha512,
            CertificateVerifyContext::Server,
            toBuf(kVerifyBuffer)->coalesce(),
            toBuf(kP256Signature)->coalesce());
      },
      "certificate verify didn't use credential's algorithm");
}

TEST_F(PeerDelegatedCredentialTest, TestCredentialVerifyBitFlip) {
  auto cred = getCredential(kP256DelegatedCred);
  auto cert = getCert(kP256CredCert);
  auto pubKeyRange = cred.public_key->coalesce();
  auto addr = pubKeyRange.data();
  folly::ssl::EvpPkeyUniquePtr pubKey(
      d2i_PUBKEY(nullptr, &addr, pubKeyRange.size()));
  auto peerCred = std::make_shared<PeerDelegatedCredentialImpl<KeyType::P256>>(
      std::move(cert), std::move(pubKey), std::move(cred));

  auto sig = toBuf(kP256Signature);
  sig->writableData()[1] ^= 0x20;
  EXPECT_THROW(
      peerCred->verify(
          SignatureScheme::ecdsa_secp256r1_sha256,
          CertificateVerifyContext::Server,
          toBuf(kVerifyBuffer)->coalesce(),
          sig->coalesce()),
      std::runtime_error);
}

TEST_F(PeerDelegatedCredentialTest, TestCredentialVerifySizeMismatch) {
  auto cred = getCredential(kP256DelegatedCred);
  auto cert = getCert(kP256CredCert);
  auto pubKeyRange = cred.public_key->coalesce();
  auto addr = pubKeyRange.data();
  folly::ssl::EvpPkeyUniquePtr pubKey(
      d2i_PUBKEY(nullptr, &addr, pubKeyRange.size()));
  auto peerCred = std::make_shared<PeerDelegatedCredentialImpl<KeyType::P256>>(
      std::move(cert), std::move(pubKey), std::move(cred));

  auto sig = toBuf(kP256Signature);
  sig->prependChain(IOBuf::copyBuffer("0"));
  EXPECT_THROW(
      peerCred->verify(
          SignatureScheme::ecdsa_secp256r1_sha256,
          CertificateVerifyContext::Server,
          toBuf(kVerifyBuffer)->coalesce(),
          sig->coalesce()),
      std::runtime_error);
}

} // namespace test
} // namespace extensions
} // namespace fizz
