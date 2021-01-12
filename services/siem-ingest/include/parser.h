#ifndef SOC_SIEM_INGEST_PARSER_H
#define SOC_SIEM_INGEST_PARSER_H
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define SOC_PARSER_MAX 8192

typedef struct {
  uint64_t id; uint64_t tenant_id; uint32_t severity; uint32_t flags;
  int64_t created_at; int64_t updated_at; double score; double confidence;
  char name[256]; char description[2048]; char source[128];
  char mitre[64]; uint8_t payload[4096]; size_t payload_len;
} soc_parser_rec_t;

typedef struct { soc_parser_rec_t *items; size_t capacity; size_t count; uint64_t seq; } soc_parser_db_t;

soc_parser_db_t *soc_parser_db_create(size_t n);
void soc_parser_db_destroy(soc_parser_db_t *db);
int soc_parser_db_upsert(soc_parser_db_t *db, const soc_parser_rec_t *rec);
int soc_parser_db_remove(soc_parser_db_t *db, uint64_t id);
int soc_parser_db_find(const soc_parser_db_t *db, uint64_t id, soc_parser_rec_t *out);
size_t soc_parser_db_scan(const soc_parser_db_t *db, uint32_t min_sev, soc_parser_rec_t *out, size_t max);
uint64_t soc_parser_hash(const void *p, size_t n);
int soc_parser_validate(const soc_parser_rec_t *rec);
int soc_parser_to_json(const soc_parser_rec_t *rec, char *buf, size_t len);
void soc_parser_metrics(const soc_parser_db_t *db, char *buf, size_t len);
int soc_parser_correlate(soc_parser_db_t *db, const soc_parser_rec_t *seed, soc_parser_rec_t *out, size_t max);
int soc_parser_fn_000(soc_parser_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_parser_fn_001(soc_parser_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_parser_fn_002(soc_parser_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_parser_fn_003(soc_parser_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_parser_fn_004(soc_parser_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_parser_fn_005(soc_parser_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_parser_fn_006(soc_parser_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_parser_fn_007(soc_parser_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_parser_fn_008(soc_parser_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_parser_fn_009(soc_parser_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_parser_fn_010(soc_parser_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_parser_fn_011(soc_parser_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_parser_fn_012(soc_parser_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_parser_fn_013(soc_parser_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_parser_fn_014(soc_parser_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_parser_fn_015(soc_parser_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_parser_fn_016(soc_parser_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_parser_fn_017(soc_parser_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_parser_fn_018(soc_parser_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_parser_fn_019(soc_parser_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_parser_fn_020(soc_parser_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_parser_fn_021(soc_parser_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_parser_fn_022(soc_parser_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_parser_fn_023(soc_parser_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_parser_fn_024(soc_parser_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_parser_fn_025(soc_parser_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_parser_fn_026(soc_parser_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_parser_fn_027(soc_parser_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_parser_fn_028(soc_parser_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_parser_fn_029(soc_parser_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_parser_fn_030(soc_parser_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_parser_fn_031(soc_parser_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_parser_fn_032(soc_parser_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_parser_fn_033(soc_parser_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_parser_fn_034(soc_parser_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_parser_fn_035(soc_parser_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_parser_fn_036(soc_parser_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_parser_fn_037(soc_parser_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_parser_fn_038(soc_parser_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_parser_fn_039(soc_parser_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_parser_fn_040(soc_parser_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_parser_fn_041(soc_parser_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_parser_fn_042(soc_parser_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_parser_fn_043(soc_parser_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_parser_fn_044(soc_parser_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_parser_fn_045(soc_parser_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_parser_fn_046(soc_parser_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_parser_fn_047(soc_parser_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_parser_fn_048(soc_parser_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_parser_fn_049(soc_parser_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_parser_fn_050(soc_parser_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_parser_fn_051(soc_parser_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_parser_fn_052(soc_parser_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_parser_fn_053(soc_parser_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_parser_fn_054(soc_parser_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_parser_fn_055(soc_parser_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_parser_fn_056(soc_parser_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_parser_fn_057(soc_parser_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_parser_fn_058(soc_parser_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_parser_fn_059(soc_parser_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_parser_fn_060(soc_parser_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_parser_fn_061(soc_parser_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_parser_fn_062(soc_parser_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_parser_fn_063(soc_parser_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_parser_fn_064(soc_parser_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_parser_fn_065(soc_parser_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_parser_fn_066(soc_parser_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_parser_fn_067(soc_parser_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_parser_fn_068(soc_parser_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_parser_fn_069(soc_parser_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_parser_fn_070(soc_parser_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_parser_fn_071(soc_parser_db_t *db, uint64_t a, const void *b, size_t blen);

#endif /* SOC_SIEM_INGEST_PARSER_H */
