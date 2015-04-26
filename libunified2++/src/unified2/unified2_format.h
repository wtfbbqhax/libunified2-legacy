/*******************************************************************************
 * Author:  Victor Roemer
 * Contact: vroemer@sourcefire.com
 * Date:    September 4, 2010
 ******************************************************************************/

#include <stdio.h>
#include <netinet/in.h>

/** UNIFIED2 FILE STRUCTURES **************************************************/

typedef struct _Unified2RecordHeader {
    uint32_t type;
    uint32_t length;
} Unified2RecordHeader;
// 8

typedef struct _Unified2Event {
    uint32_t sensor_id;
    uint32_t event_id;
    uint32_t event_second;
    uint32_t event_microsecond;
    uint32_t signature_id;
    uint32_t generator_id;
    uint32_t signature_revision;
    uint32_t classification_id;
    uint32_t priority_id;
    uint32_t ip_source;
    uint32_t ip_destination;
    uint16_t sport_itype;
    uint16_t dport_icode;
    uint8_t  protocol;
    uint8_t  packet_action;
    uint16_t pad;
} Unified2Event;
// 52

typedef struct _Unified2Event_v2
{
    uint32_t sensor_id;
    uint32_t event_id;
    uint32_t event_second;
    uint32_t event_microsecond;
    uint32_t signature_id;
    uint32_t generator_id;
    uint32_t signature_revision;
    uint32_t classification_id;
    uint32_t priority_id;
    uint32_t ip_source;
    uint32_t ip_destination;
    uint16_t sport_itype;
    uint16_t dport_icode;
    uint8_t  protocol;
    uint8_t  packet_action;
    uint16_t pad;
    uint32_t mpls_label;
    uint16_t vlan_id;
    uint16_t policy_id;
} Unified2Event_v2;
// 60

typedef struct _Unified2Event6 {
    uint32_t sensor_id;
    uint32_t event_id;
    uint32_t event_second;
    uint32_t event_microsecond;
    uint32_t signature_id;
    uint32_t generator_id;
    uint32_t signature_revision;
    uint32_t classification_id;
    uint32_t priority_id;
    struct in6_addr ip_source;
    struct in6_addr ip_destination;
    uint16_t sport_itype;
    uint16_t dport_icode;
    uint8_t  protocol;
    uint8_t  packet_action;
    uint16_t pad;
} Unified2Event6;

typedef struct _Unified2Event6_v2 {
    uint32_t sensor_id;
    uint32_t event_id;
    uint32_t event_second;
    uint32_t event_microsecond;
    uint32_t signature_id;
    uint32_t generator_id;
    uint32_t signature_revision;
    uint32_t classification_id;
    uint32_t priority_id;
    struct in6_addr ip_source;
    struct in6_addr ip_destination;
    uint16_t sport_itype;
    uint16_t dport_icode;
    uint8_t  protocol;
    uint8_t  packet_action;
    uint16_t pad;
    uint32_t mpls_label;
    uint16_t vlan_id;
    uint16_t policy_id;
} Unified2Event6_v2;

typedef struct _Unified2Packet {
    uint32_t sensor_id;
    uint32_t event_id;
    uint32_t event_second;
    uint32_t packet_second;
    uint32_t packet_microsecond;
    uint32_t linktype;
    uint32_t packet_length;
} Unified2Packet;

typedef struct _Unified2Extra {
    uint32_t sensor_id;
    uint32_t event_id;
    uint32_t event_second;
    uint32_t type; /* EventInfo */
    uint32_t data_type; /* EventDataType */
    uint32_t extra_length;
} Unified2Extra;



/** LOCAL DATA STRUCTURES ******************************************************/

typedef struct _Unified2Entry {
    Unified2RecordHeader    *record;
    Unified2Event           *event;
    Unified2Event_v2        *event_v2;
    Unified2Event6          *event6;
    Unified2Event6_v2       *event6_v2;
    Unified2Packet          *packet;
    void                    *packet_data;
    Unified2Extra           *extra;
    void                    *extra_data;
} Unified2Entry;

typedef enum _RECORD_TYPE {
    UNIFIED2_EVENT = 1,
    UNIFIED2_PACKET = 2,
    UNIFIED2_IDS_EVENT = 7,
    UNIFIED2_EVENT_EXTENDED = 66,
    UNIFIED2_PERFORMANCE = 67,
    UNIFIED2_PORTSCAN = 68,
    UNIFIED2_IDS_EVENT_IPV6 = 72,
    UNIFIED2_IDS_EVENT_MPLS = 99,
    UNIFIED2_IDS_EVENT_IPV6_MPLS = 100,
    UNIFIED2_IDS_EVENT_V2 = 104,
    UNIFIED2_IDS_EVENT_IPV6_V2 = 105,
    UNIFIED2_EXTRA_DATA = 110,
} RECORD_TYPE;

typedef enum _EventInfoEnum {
    EVENT_INFO_XFF_IPV4 = 1,
    EVENT_INFO_XFF_IPV6,
    EVENT_INFO_REVIEWED_BY,
    EVENT_INFO_GZIP_DATA
} EventInfoEnum;

typedef enum _EventDataType {
    EVENT_DATA_TYPE_BLOB = 1,
    EVENT_DATA_TYPE_MAX
} EventDataType;
