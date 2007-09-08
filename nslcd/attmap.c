/*
   attmap.c - attribute mapping values and functions
   This file is part of the nss-ldapd library.

   Copyright (C) 2007 Arthur de Jong

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with this library; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
   02110-1301 USA
*/

#include "config.h"

#include <stdlib.h>
#include <strings.h>

#include "attmap.h"

const char *attmap_objectClass           = "objectClass";

const char **filter_get_var(enum ldap_map_selector map)
{
  switch (map)
  {
    case LM_ALIASES:   return &alias_filter;
    case LM_ETHERS:    return &ether_filter;
    case LM_GROUP:     return &group_filter;
    case LM_HOSTS:     return &host_filter;
    case LM_NETGROUP:  return &netgroup_filter;
    case LM_NETWORKS:  return &network_filter;
    case LM_PASSWD:    return &passwd_filter;
    case LM_PROTOCOLS: return &protocol_filter;
    case LM_RPC:       return &rpc_filter;
    case LM_SERVICES:  return &service_filter;
    case LM_SHADOW:    return &shadow_filter;
    case LM_NONE:
    default:           return NULL;
  }
}

const char **attmap_get_var(enum ldap_map_selector map,const char *name)
{
  if (map==LM_ALIASES)
  {
    if (strcasecmp(name,"cn")==0)                return &attmap_alias_cn;
    if (strcasecmp(name,"rfc822MailMember")==0)  return &attmap_alias_rfc822MailMember;
  }
  else if (map==LM_ETHERS)
  {
    if (strcasecmp(name,"cn")==0)                return &attmap_ether_cn;
    if (strcasecmp(name,"macAddress")==0)        return &attmap_ether_macAddress;
  }
  else if (map==LM_GROUP)
  {
    if (strcasecmp(name,"cn")==0)                return &attmap_group_cn;
    if (strcasecmp(name,"userPassword")==0)      return &attmap_group_userPassword;
    if (strcasecmp(name,"gidNumber")==0)         return &attmap_group_gidNumber;
    if (strcasecmp(name,"memberUid")==0)         return &attmap_group_memberUid;
    if (strcasecmp(name,"uniqueMember")==0)      return &attmap_group_uniqueMember;
    if (strcasecmp(name,"memberOf")==0)          return &attmap_group_memberOf;
  }
  else if (map==LM_HOSTS)
  {
    if (strcasecmp(name,"cn")==0)                return &attmap_host_cn;
    if (strcasecmp(name,"ipHostNumber")==0)      return &attmap_host_ipHostNumber;
  }
  else if (map==LM_NETGROUP)
  {
    if (strcasecmp(name,"cn")==0)                return &attmap_netgroup_cn;
    if (strcasecmp(name,"nisNetgroupTriple")==0) return &attmap_netgroup_nisNetgroupTriple;
    if (strcasecmp(name,"memberNisNetgroup")==0) return &attmap_netgroup_memberNisNetgroup;
  }
  else if (map==LM_NETWORKS)
  {
    if (strcasecmp(name,"cn")==0)                return &attmap_network_cn;
    if (strcasecmp(name,"ipNetworkNumber")==0)   return &attmap_network_ipNetworkNumber;
  }
  else if (map==LM_PASSWD)
  {
    if (strcasecmp(name,"uid")==0)               return &attmap_passwd_uid;
    if (strcasecmp(name,"userPassword")==0)      return &attmap_passwd_userPassword;
    if (strcasecmp(name,"uidNumber")==0)         return &attmap_passwd_uidNumber;
    if (strcasecmp(name,"gidNumber")==0)         return &attmap_passwd_gidNumber;
    if (strcasecmp(name,"gecos")==0)             return &attmap_passwd_gecos;
    if (strcasecmp(name,"cn")==0)                return &attmap_passwd_cn;
    if (strcasecmp(name,"homeDirectory")==0)     return &attmap_passwd_homeDirectory;
    if (strcasecmp(name,"loginShell")==0)        return &attmap_passwd_loginShell;
  }
  else if (map==LM_PROTOCOLS)
  {
    if (strcasecmp(name,"cn")==0)                return &attmap_protocol_cn;
    if (strcasecmp(name,"ipProtocolNumber")==0)  return &attmap_protocol_ipProtocolNumber;
  }
  else if (map==LM_RPC)
  {
    if (strcasecmp(name,"cn")==0)                return &attmap_rpc_cn;
    if (strcasecmp(name,"oncRpcNumber")==0)      return &attmap_rpc_oncRpcNumber;
  }
  else if (map==LM_SERVICES)
  {
    if (strcasecmp(name,"cn")==0)                return &attmap_service_cn;
    if (strcasecmp(name,"ipServicePort")==0)     return &attmap_service_ipServicePort;
    if (strcasecmp(name,"ipServiceProtocol")==0) return &attmap_service_ipServiceProtocol;
  }
  else if (map==LM_SHADOW)
  {
    if (strcasecmp(name,"uid")==0)               return &attmap_shadow_uid;
    if (strcasecmp(name,"userPassword")==0)      return &attmap_shadow_userPassword;
    if (strcasecmp(name,"shadowLastChange")==0)  return &attmap_shadow_shadowLastChange;
    if (strcasecmp(name,"shadowMin")==0)         return &attmap_shadow_shadowMin;
    if (strcasecmp(name,"shadowMax")==0)         return &attmap_shadow_shadowMax;
    if (strcasecmp(name,"shadowWarning")==0)     return &attmap_shadow_shadowWarning;
    if (strcasecmp(name,"shadowInactive")==0)    return &attmap_shadow_shadowInactive;
    if (strcasecmp(name,"shadowExpire")==0)      return &attmap_shadow_shadowExpire;
    if (strcasecmp(name,"shadowFlag")==0)        return &attmap_shadow_shadowFlag;
  }
  return NULL;
}
