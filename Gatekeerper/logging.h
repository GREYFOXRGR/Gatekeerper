/*
 *
 *               ('-.     .-') _     ('-.  .-. .-')     ('-.     ('-.  _  .-')     _ (`-.    ('-.  _  .-')
 *              ( OO ).-.(  OO) )  _(  OO) \  ( OO )  _(  OO)  _(  OO)( \( -O )   ( (OO  ) _(  OO)( \( -O )
 *  ,----.      / . --. //     '._(,------.,--. ,--. (,------.(,------.,------.  _.`     \(,------.,------.
 *  '  .-./-')   | \-.  \ |'--...__)|  .---'|  .'   /  |  .---' |  .---'|   /`. '(__...--'' |  .---'|   /`. '
 *  |  |_( O- ).-'-'  |  |'--.  .--'|  |    |      /,  |  |     |  |    |  /  | | |  /  | | |  |    |  /  | |
 *  |  | .--, \ \| |_.'  |   |  |  (|  '--. |     ' _)(|  '--. (|  '--. |  |_.' | |  |_.' |(|  '--. |  |_.' |
 * (|  | '. (_/  |  .-.  |   |  |   |  .--' |  .   \   |  .--'  |  .--' |  .  '.' |  .___.' |  .--' |  .  '.'
 *  |  '--'  |   |  | |  |   |  |   |  `---.|  |\   \  |  `---. |  `---.|  |\  \  |  |      |  `---.|  |\  \
 *  `------'    `--' `--'   `--'   `------'`--' '--'  `------' `------'`--' '--' `--'      `------'`--' '--'
 *
 * Gatekeerper
 * A kernel extension to mitigate Gatekeeper bypasses
 * Doesn't let linked (frameworks, libraries, bundles) unsigned code run if main binary is signed
 *
 * Untested with latest Gatekeeper bypass, too lazy to create a PoC of that
 * So I'm just guessing it will work, I'm pretty confident anyway :P
 *
 * Not guaranteed to be secure code! It might even destroy your computer but that is your problem! 
 *
 * Created by reverser on 01/10/15.
 * Copyright (c) fG!, 2015. All rights reserved.
 * reverser@put.as - https://reverse.put.as
 *
 * logging.h
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 * derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef gatekeerper_logging_h
#define gatekeerper_logging_h

#include <libkern/libkern.h>

#if DEBUG == NO

#define DEBUG_MSG(fmt, ...) do {} while (0)
#define ERROR_MSG(fmt, ...) printf("[ERROR] " fmt "\n", ## __VA_ARGS__)

#else /* DEBUG == YES */

#define DEBUG_MSG(fmt, ...) printf("[DEBUG] " fmt "\n", ##  __VA_ARGS__)
#define ERROR_MSG(fmt, ...) printf("[ERROR] " fmt " (%s, %d)\n", ## __VA_ARGS__, __func__, __LINE__)

#endif /* DEBUG */

/* kernel symbols */
#define SOLVE_KERNEL_SYMBOL(string, pointer) if (solve_kernel_symbol((string), (void**)&(pointer))) { ERROR_MSG("Can't solve kernel symbol %s", (string)); return KERN_FAILURE;}
#define SOLVE_KERNEL_VARIABLE(string, output) if (solve_kernel_variable((string), &(output))) { ERROR_MSG("Can't solve kernel variable %s", (string)); return KERN_FAILURE;}

#endif
