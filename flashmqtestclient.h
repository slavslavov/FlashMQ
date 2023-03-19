#ifndef FLASHMQTESTCLIENT_H
#define FLASHMQTESTCLIENT_H

#include <thread>
#include <memory>

#include "subscriptionstore.h"
#include "pluginloader.h"

/**
 * @brief The FlashMQTestClient class uses the existing server code as a client, for testing purposes.
 */
class FlashMQTestClient
{
    PluginLoader pluginLoader;
    Settings settings;
    std::shared_ptr<ThreadData> testServerWorkerThreadData;
    std::shared_ptr<Client> client;
    std::shared_ptr<WillPublish> will;

    std::shared_ptr<ThreadData> dummyThreadData;

    std::mutex receivedListMutex;

    static int clientCount;

    void waitForCondition(std::function<bool()> f, int timeout = 1);


public:
    std::vector<MqttPacket> receivedPackets;
    std::vector<MqttPacket> receivedPublishes;

    FlashMQTestClient();
    ~FlashMQTestClient();

    void start();
    void connectClient(ProtocolVersion protocolVersion);
    void connectClient(ProtocolVersion protocolVersion, bool clean_start, uint32_t session_expiry_interval);
    void connectClient(ProtocolVersion protocolVersion, bool clean_start, uint32_t session_expiry_interval, std::function<void(Connect&)> manipulateConnect);
    void subscribe(const std::string topic, uint8_t qos);
    void unsubscribe(const std::string &topic);
    void publish(const std::string &topic, const std::string &payload, uint8_t qos);
    void publish(Publish &pub);
    void writeAuth(const Auth &auth);
    void clearReceivedLists();
    void setWill(std::shared_ptr<WillPublish> &will);
    void disconnect(ReasonCodes reason);

    void waitForQuit();
    void waitForConnack();
    void waitForDisconnectPacket();
    void waitForMessageCount(const size_t count, int timeout = 1);
    void waitForPacketCount(const size_t count, int timeout = 1);

    std::shared_ptr<Client> &getClient();
};

#endif // FLASHMQTESTCLIENT_H
