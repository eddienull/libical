/*======================================================================
 FILE: icalvalue_cxx.cpp
 CREATOR: fnguyen 12/21/01
 (C) COPYRIGHT 2001, Critical Path

 This program is free software; you can redistribute it and/or modify
 it under the terms of either:

    The LGPL as published by the Free Software Foundation, version
    2.1, available at: http://www.gnu.org/licenses/lgpl-2.1.html

  Or:

    The Mozilla Public License Version 1.0. You may obtain a copy of
    the License at http://www.mozilla.org/MPL/
======================================================================*/

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include "icalvalue_cxx.h"
using namespace LibICal;

ICalValue::ICalValue() throw(icalerrorenum) : imp(icalvalue_new(ICAL_ANY_VALUE))
{
}

ICalValue::ICalValue(const ICalValue &v) throw (icalerrorenum)
{
    imp = icalvalue_new_clone(v.imp);
    if (imp == NULL) {
        throw icalerrno;
    }
}

ICalValue &ICalValue::operator=(const ICalValue &v) throw(icalerrorenum)
{
    if (this == &v) {
        return *this;
    }

    if (imp != NULL) {
        icalvalue_free(imp);
        imp = icalvalue_new_clone(v.imp);
        if (imp == NULL) {
            throw icalerrno;
        }
    }

    return *this;
}

void ICalValue::detach()
{
    imp = NULL;
}

ICalValue::~ICalValue()
{
    if (imp != NULL) {
        icalvalue_free(imp);
    }
}

ICalValue::ICalValue(icalvalue *v) throw(icalerrorenum) : imp(v)
{
}

ICalValue::ICalValue(const icalvalue_kind &kind) throw(icalerrorenum)
{
    imp = icalvalue_new(kind);
    if (imp == NULL) {
        throw icalerrno;
    }
}

ICalValue::ICalValue(const icalvalue_kind &kind, const std::string &str) throw(icalerrorenum)
{
    imp = icalvalue_new_from_string(kind, str.c_str());
    if (imp == NULL) {
        throw icalerrno;
    }
}

std::string ICalValue::as_ical_string()
{
    return (std::string)icalvalue_as_ical_string(imp);
}

bool ICalValue::is_valid()
{
    if (imp == NULL) {
        return false;
    }
    return (icalvalue_is_valid(imp) ? true : false);
}

icalvalue_kind ICalValue::isa()
{
    return icalvalue_isa(imp);
}

int ICalValue::isa_value(void *value)
{
    return icalvalue_isa_value(value);
}

/* Special, non autogenerated value accessors */
void ICalValue::set_recur(const struct icalrecurrencetype &v)
{
    icalvalue_set_recur(imp, v);
}

struct icalrecurrencetype ICalValue::get_recur()
{
    return icalvalue_get_recur(imp);
}

void ICalValue::set_trigger(const struct icaltriggertype &v)
{
    _unused(v)
}

struct icaltriggertype ICalValue::get_trigger()
{
    return icalvalue_get_trigger(imp);
}

void ICalValue::set_datetimeperiod(const struct icaldatetimeperiodtype &v)
{
    icalvalue_set_datetimeperiod(imp, v);
}

struct icaldatetimeperiodtype ICalValue::get_datetimeperiod()
{
    return icalvalue_get_datetimeperiod(imp);
}

icalparameter_xliccomparetype ICalValue::compare(ICalValue &a, ICalValue &b)
{
    return icalvalue_compare(a, b);
}

/* Convert enumerations */
icalvalue_kind ICalValue::string_to_kind(const std::string &str)
{
    return icalvalue_string_to_kind(str.c_str());
}

std::string ICalValue::kind_to_string(const icalvalue_kind &kind)
{
    return (std::string)icalvalue_kind_to_string(kind);
}

/* BOOLEAN */
int ICalValue::get_boolean() const
{
    return icalvalue_get_boolean(imp);
}

void ICalValue::set_boolean(const int &v)
{
    icalvalue_set_boolean(imp, v);
}

/* UTC-OFFSET */
int ICalValue::get_utcoffset() const
{
    return icalvalue_get_utcoffset(imp);
}

void ICalValue::set_utcoffset(const int &v)
{
    icalvalue_set_utcoffset(imp, v);
}

/* METHOD */
enum icalproperty_method ICalValue::get_method() const
{
    return icalvalue_get_method(imp);
}

void ICalValue::set_method(const enum icalproperty_method &v)
{
    icalvalue_set_method(imp, v);
}

/* CAL-ADDRESS */
std::string ICalValue::get_caladdress() const
{
    return (std::string)icalvalue_get_caladdress(imp);
}

void ICalValue::set_caladdress(const std::string &v)
{
    icalvalue_set_caladdress(imp, v.c_str());
}

/* PERIOD */
struct icalperiodtype ICalValue::get_period() const
{
    return icalvalue_get_period(imp);
}

void ICalValue::set_period(const struct icalperiodtype &v)
{
    icalvalue_set_period(imp, v);
}

/* STATUS */
enum icalproperty_status ICalValue::get_status() const
{
    return icalvalue_get_status(imp);
}

void ICalValue::set_status(const enum icalproperty_status &v)
{
    icalvalue_set_status(imp, v);
}

/* BINARY */
std::string ICalValue::get_binary() const
{
    return (std::string)icalvalue_get_binary(imp);
}

void ICalValue::set_binary(const std::string &v)
{
    icalvalue_set_binary(imp, v.c_str());
}

/* TEXT */
std::string ICalValue::get_text() const
{
    return (std::string)icalvalue_get_text(imp);
}

void ICalValue::set_text(const std::string &v)
{
    icalvalue_set_text(imp, v.c_str());
}

/* DURATION */
struct icaldurationtype ICalValue::get_duration() const
{
    return icalvalue_get_duration(imp);
}

void ICalValue::set_duration(const struct icaldurationtype &v)
{
    icalvalue_set_duration(imp, v);
}

/* INTEGER */
int ICalValue::get_integer() const
{
    return icalvalue_get_integer(imp);
}

void ICalValue::set_integer(const int &v)
{
    icalvalue_set_integer(imp, v);
}

/* URI */
std::string ICalValue::get_uri() const
{
    return (std::string)icalvalue_get_uri(imp);
}

void ICalValue::set_uri(const std::string &v)
{
    icalvalue_set_uri(imp, v.c_str());
}

/* ATTACH */
icalattach *ICalValue::get_attach()
{
    return icalvalue_get_attach(imp);
}

void ICalValue::set_attach(icalattach *v)
{
    icalvalue_set_attach(imp, v);
}

/* CLASS */
enum icalproperty_class ICalValue::get_class() const
{
    return icalvalue_get_class(imp);
}

void ICalValue::set_class(const enum icalproperty_class &v)
{
    icalvalue_set_class(imp, v);
}

/* FLOAT */
float ICalValue::get_float() const
{
    return icalvalue_get_float(imp);
}

void ICalValue::set_float(const float &v)
{
    icalvalue_set_float(imp, v);
}

/* QUERY */
std::string ICalValue::get_query() const
{
    return (std::string)icalvalue_get_query(imp);
}

void ICalValue::set_query(const std::string &v)
{
    icalvalue_set_query(imp, v.c_str());
}

/* STRING */
std::string ICalValue::get_string() const
{
    return (std::string)icalvalue_get_string(imp);
}

void ICalValue::set_string(const std::string &v)
{
    icalvalue_set_string(imp, v.c_str());
}

/* TRANSP */
enum icalproperty_transp ICalValue::get_transp() const
{
    return icalvalue_get_transp(imp);
}

void ICalValue::set_transp(const enum icalproperty_transp &v)
{
    icalvalue_set_transp(imp, v);
}

/* DATE-TIME */
struct icaltimetype ICalValue::get_datetime() const
{
    return icalvalue_get_datetime(imp);
}

void ICalValue::set_datetime(const struct icaltimetype &v)
{
    icalvalue_set_datetime(imp, v);
}

/* GEO */
struct icalgeotype ICalValue::get_geo() const
{
    return icalvalue_get_geo(imp);
}

void ICalValue::set_geo(const struct icalgeotype &v)
{
    icalvalue_set_geo(imp, v);
}

/* DATE */
struct icaltimetype ICalValue::get_date() const
{
    return icalvalue_get_date(imp);
}

void ICalValue::set_date(const struct icaltimetype &v)
{
    icalvalue_set_date(imp, v);
}

/* ACTION */
enum icalproperty_action ICalValue::get_action() const
{
    return icalvalue_get_action(imp);
}

void ICalValue::set_action(const enum icalproperty_action &v)
{
    icalvalue_set_action(imp, v);
}
