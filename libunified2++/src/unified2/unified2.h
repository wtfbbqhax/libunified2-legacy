#ifndef __UNIFIED2_CPP_H__
#define __UNIFIED2_CPP_H__

class Unified2
{
public:
    // Unified2Event
    uint32_t SensorID( );
    uint32_t EventID( );
    uint32_t EventSecond( );
    uint32_t EventMicroSecond( );
    uint32_t SignatureID( );
    uint32_t GeneratorID( );
    uint32_t SignatureRev( );
    uint32_t ClassificationID( );
    uint32_t PriorityID( );
    string SourceIP( );
    string DestinationIP( );
    uint32_t SourcePort( );
    uint32_t DestinationPort( );
    uint8_t Protocol( );
    string ProtocolStirng( );
    uint32_t MPLSLabel( );
    uint16_t VlanID( );
    uint16_t PolicyID( );

    // Unified2Packet
    uint32_t PacketSecond( );
    uint32_t PacketMicroSecond( );
    uint32_t LinkType( );
    string LinkTypeString( );
    uint32_t PacketLength( );
    void* PacketData( );

    // Unfied2Extra
    string ExtraData( );
}

#endif
