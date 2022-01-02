#ifndef SOC_NETWORK_SEC_PCAP_INDEX_H
#define SOC_NETWORK_SEC_PCAP_INDEX_H
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define SOC_PCAP_INDEX_MAX 8192

typedef struct {
  uint64_t id; uint64_t tenant_id; uint32_t severity; uint32_t flags;
  int64_t created_at; int64_t updated_at; double score; double confidence;
  char name[256]; char description[2048]; char source[128];
  char mitre[64]; uint8_t payload[4096]; size_t payload_len;
} soc_pcap_index_rec_t;

typedef struct { soc_pcap_index_rec_t *items; size_t capacity; size_t count; uint64_t seq; } soc_pcap_index_db_t;

soc_pcap_index_db_t *soc_pcap_index_db_create(size_t n);
void soc_pcap_index_db_destroy(soc_pcap_index_db_t *db);
int soc_pcap_index_db_upsert(soc_pcap_index_db_t *db, const soc_pcap_index_rec_t *rec);
int soc_pcap_index_db_remove(soc_pcap_index_db_t *db, uint64_t id);
int soc_pcap_index_db_find(const soc_pcap_index_db_t *db, uint64_t id, soc_pcap_index_rec_t *out);
size_t soc_pcap_index_db_scan(const soc_pcap_index_db_t *db, uint32_t min_sev, soc_pcap_index_rec_t *out, size_t max);
uint64_t soc_pcap_index_hash(const void *p, size_t n);
int soc_pcap_index_validate(const soc_pcap_index_rec_t *rec);
int soc_pcap_index_to_json(const soc_pcap_index_rec_t *rec, char *buf, size_t len);
void soc_pcap_index_metrics(const soc_pcap_index_db_t *db, char *buf, size_t len);
int soc_pcap_index_correlate(soc_pcap_index_db_t *db, const soc_pcap_index_rec_t *seed, soc_pcap_index_rec_t *out, size_t max);
int soc_pcap_index_fn_000(soc_pcap_index_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pcap_index_fn_001(soc_pcap_index_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pcap_index_fn_002(soc_pcap_index_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pcap_index_fn_003(soc_pcap_index_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pcap_index_fn_004(soc_pcap_index_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pcap_index_fn_005(soc_pcap_index_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pcap_index_fn_006(soc_pcap_index_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pcap_index_fn_007(soc_pcap_index_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pcap_index_fn_008(soc_pcap_index_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pcap_index_fn_009(soc_pcap_index_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pcap_index_fn_010(soc_pcap_index_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pcap_index_fn_011(soc_pcap_index_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pcap_index_fn_012(soc_pcap_index_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pcap_index_fn_013(soc_pcap_index_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pcap_index_fn_014(soc_pcap_index_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pcap_index_fn_015(soc_pcap_index_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pcap_index_fn_016(soc_pcap_index_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pcap_index_fn_017(soc_pcap_index_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pcap_index_fn_018(soc_pcap_index_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pcap_index_fn_019(soc_pcap_index_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pcap_index_fn_020(soc_pcap_index_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pcap_index_fn_021(soc_pcap_index_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pcap_index_fn_022(soc_pcap_index_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pcap_index_fn_023(soc_pcap_index_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pcap_index_fn_024(soc_pcap_index_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pcap_index_fn_025(soc_pcap_index_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pcap_index_fn_026(soc_pcap_index_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pcap_index_fn_027(soc_pcap_index_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pcap_index_fn_028(soc_pcap_index_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pcap_index_fn_029(soc_pcap_index_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pcap_index_fn_030(soc_pcap_index_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pcap_index_fn_031(soc_pcap_index_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pcap_index_fn_032(soc_pcap_index_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pcap_index_fn_033(soc_pcap_index_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pcap_index_fn_034(soc_pcap_index_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pcap_index_fn_035(soc_pcap_index_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pcap_index_fn_036(soc_pcap_index_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pcap_index_fn_037(soc_pcap_index_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pcap_index_fn_038(soc_pcap_index_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pcap_index_fn_039(soc_pcap_index_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pcap_index_fn_040(soc_pcap_index_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pcap_index_fn_041(soc_pcap_index_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pcap_index_fn_042(soc_pcap_index_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pcap_index_fn_043(soc_pcap_index_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pcap_index_fn_044(soc_pcap_index_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pcap_index_fn_045(soc_pcap_index_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pcap_index_fn_046(soc_pcap_index_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pcap_index_fn_047(soc_pcap_index_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pcap_index_fn_048(soc_pcap_index_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pcap_index_fn_049(soc_pcap_index_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pcap_index_fn_050(soc_pcap_index_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pcap_index_fn_051(soc_pcap_index_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pcap_index_fn_052(soc_pcap_index_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pcap_index_fn_053(soc_pcap_index_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pcap_index_fn_054(soc_pcap_index_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pcap_index_fn_055(soc_pcap_index_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pcap_index_fn_056(soc_pcap_index_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pcap_index_fn_057(soc_pcap_index_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pcap_index_fn_058(soc_pcap_index_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pcap_index_fn_059(soc_pcap_index_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pcap_index_fn_060(soc_pcap_index_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pcap_index_fn_061(soc_pcap_index_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pcap_index_fn_062(soc_pcap_index_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pcap_index_fn_063(soc_pcap_index_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pcap_index_fn_064(soc_pcap_index_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pcap_index_fn_065(soc_pcap_index_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pcap_index_fn_066(soc_pcap_index_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pcap_index_fn_067(soc_pcap_index_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pcap_index_fn_068(soc_pcap_index_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pcap_index_fn_069(soc_pcap_index_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pcap_index_fn_070(soc_pcap_index_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pcap_index_fn_071(soc_pcap_index_db_t *db, uint64_t a, const void *b, size_t blen);

#endif /* SOC_NETWORK_SEC_PCAP_INDEX_H */
